#include "SimpleTCPLogSender.h"

#include <boost/array.hpp>
#include <utility>
#include <thread>

SimpleTCPLogSender::SimpleTCPLogSender(std::string serverHost, unsigned short serverPort, unsigned int awaitPeriod, unsigned int loggedLevelFrom, unsigned int loggedLevelTo)
        : LogSenderAbstract(loggedLevelFrom, loggedLevelTo)
{
    this->serverHost = std::move(serverHost);
    this->serverPort = serverPort;
    this->queue = std::unique_ptr<LogQueue>(new LogQueue());
    this->awaitPeriod = awaitPeriod;
}

void SimpleTCPLogSender::initHandler(){
    this->endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(this->serverHost), this->serverPort);
    this->socket = boost::shared_ptr< boost::asio::ip::tcp::socket>(new boost::asio::ip::tcp::socket(this->ios));

    std::thread tWorker(&SimpleTCPLogSender::worker, this);
    tWorker.detach();
};

void SimpleTCPLogSender::sendMessage(std::shared_ptr<MessageAbstract> message) {
    this->queue->pushMessage(std::move(message));
}

void SimpleTCPLogSender::worker() {
    while(workerRunning) {
        socket->connect(endpoint);

        while (auto message = this->queue->popMessage()) {
            this->sendMessageAsync(message);
        }

        socket->close();
        std::this_thread::sleep_for(std::chrono::milliseconds(this->awaitPeriod));
    }
}

void SimpleTCPLogSender::sendMessageAsync(std::shared_ptr<MessageAbstract> message) {
    std::string formattedMessage = this->getFinalMessage(message);
    boost::system::error_code error;

    boost::array<char, PACKET_BUFFER_SIZE> buf{};
    std::copy(formattedMessage.begin(), formattedMessage.end(), buf.begin());

    socket->write_some(boost::asio::buffer(buf, formattedMessage.size()), error);
}
