#ifndef DYALOG_SIMPLETCPSENDER_H
#define DYALOG_SIMPLETCPSENDER_H

#define PACKET_BUFFER_SIZE 65000

#include "../LogSenderAbstract.h"
#include <boost/asio.hpp>
#include "boost/scoped_ptr.hpp"

class SimpleTCPLogSender : public LogSenderAbstract {
public:
    SimpleTCPLogSender(std::string serverHost, unsigned short serverPort, unsigned int loggedLevel = 0);
    void initHandler();
    void sendMessage(std::shared_ptr<MessageAbstract> message);

private:
    std::string getFormattedMessage(std::shared_ptr<MessageAbstract> message);

    boost::asio::io_service ios;
    boost::asio::ip::tcp::endpoint endpoint;
    std::string serverHost;
    unsigned short serverPort;
    boost::shared_ptr<boost::asio::ip::tcp::socket> socket;
};


#endif //DYALOG_SIMPLETCPSENDER_H
