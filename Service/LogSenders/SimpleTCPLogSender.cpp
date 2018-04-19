#include "SimpleTCPLogSender.h"

#include <boost/array.hpp>
#include <utility>

SimpleTCPLogSender::SimpleTCPLogSender(std::string serverHost, unsigned short serverPort, unsigned int loggedLevel) : LogSenderAbstract(loggedLevel) {
    this->serverHost = std::move(serverHost);
    this->serverPort = serverPort;
}

void SimpleTCPLogSender::initHandler(){
    this->endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(this->serverHost), this->serverPort);
    this->socket = boost::shared_ptr< boost::asio::ip::tcp::socket>(new boost::asio::ip::tcp::socket(this->ios));
};

void SimpleTCPLogSender::sendMessage(std::shared_ptr<MessageAbstract> message) {
    std::string formattedMessage = getFormattedMessage(message);
    socket->connect(endpoint);
    boost::array<char, PACKET_BUFFER_SIZE> buf;
    std::copy(formattedMessage.begin(),formattedMessage.end(),buf.begin());
    boost::system::error_code error;
    socket->write_some(boost::asio::buffer(buf, formattedMessage.size()), error);
    socket->close();
}

std::string SimpleTCPLogSender::getFormattedMessage(std::shared_ptr<MessageAbstract> message) {
    std::string finalMessage = "";

    if (this->formatter != NULL){
        finalMessage = this->formatter->getFormattedMessage(message);
    } else {
        finalMessage = message->getMessage();
    }

    return finalMessage;
}
