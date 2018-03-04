#ifndef DYALOG_LOGMANAGER_H
#define DYALOG_LOGMANAGER_H


#include <memory>
#include <list>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "LogSenderAbstract.h"
#include "LogWriterAbstract.h"

class LogManager {

public:
    LogManager(std::shared_ptr<Configuration> config);
    void processMessage(std::shared_ptr<MessageAbstract> message);

    void addSender(std::shared_ptr<LogSenderAbstract> sender);
    std::list<std::shared_ptr<LogSenderAbstract>> getSenders();

    void addWriter(std::shared_ptr<LogWriterAbstract> writer);
    std::list<std::shared_ptr<LogWriterAbstract>> getWriters();

protected:
    std::shared_ptr<Configuration> config;

private:
    std::list<std::shared_ptr<LogSenderAbstract>> senders;
    std::list<std::shared_ptr<LogWriterAbstract>> writers;
};


#endif //DYALOG_LOGMANAGER_H
