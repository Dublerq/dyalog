#ifndef DYALOG_SIMPLETCPSENDER_H
#define DYALOG_SIMPLETCPSENDER_H

#define PACKET_BUFFER_SIZE 65000

#include "../LogSenderAbstract.h"
#include <boost/asio.hpp>
#include "boost/scoped_ptr.hpp"
#include "../../Model/LogQueue.h"

/**
 * @brief Log handler for sending messages over tcp to a target server
 */
class SimpleTCPLogSender : public LogSenderAbstract {
public:
    /**
     * @param serverHost target server ip
     * @param serverPort target server port
     * @param awaitPeriod wait period between connections
     * @param loggedLevelFrom minimal log level
     * @param loggedLevelTo maxmial log level
     */
    SimpleTCPLogSender(std::string serverHost, unsigned short serverPort, unsigned int awaitPeriod = 1000, unsigned int loggedLevelFrom = 0, unsigned int loggedLevelTo = 9999);

    /// @inherit
    void initHandler();

    /// @inherit
    void sendMessage(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Async thread worker running forever unless application is closed or stopWorker method was performed
     * Sends data to the target serget server
     */
    void worker();

    /**
     * @brief Method allowing to stop worker
     */
    void stopWorker() { this->workerRunning = false; }

private:
    /**
     * @brief Send a log from async worker to the target server over connected socket
     * @param message model
     */
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
