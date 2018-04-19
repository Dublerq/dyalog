#ifndef DYALOG_SIMPLETCPSENDER_H
#define DYALOG_SIMPLETCPSENDER_H

#define PACKET_BUFFER_SIZE 65000

#include "../LogSenderAbstract.h"
#include <boost/asio.hpp>
#include "boost/scoped_ptr.hpp"
#include "../../Model/LogQueue.h"

class SimpleTCPLogSender : public LogSenderAbstract {
public:
    SimpleTCPLogSender(std::string serverHost, unsigned short serverPort, unsigned int awaitPeriod = 1000, unsigned int loggedLevelFrom = 0, unsigned int loggedLevelTo = 9999);
    void initHandler();
    void sendMessage(std::shared_ptr<MessageAbstract> message);
    void worker();
    void stopWorker() { this->workerRunning = false; }

private:
    void sendMessageAsync(std::shared_ptr<MessageAbstract> message);

    std::unique_ptr<LogQueue> queue;
    bool workerRunning = true;
    unsigned int awaitPeriod;

    unsigned short serverPort;
    std::string serverHost;

    boost::asio::io_service ios;
    boost::asio::ip::tcp::endpoint endpoint;
    boost::shared_ptr<boost::asio::ip::tcp::socket> socket;
};


#endif //DYALOG_SIMPLETCPSENDER_H
