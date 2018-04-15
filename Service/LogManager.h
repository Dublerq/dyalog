#ifndef DYALOG_LOGMANAGER_H
#define DYALOG_LOGMANAGER_H


#include <memory>
#include <list>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "LogHandlerAbstract.h"

class LogManager {

public:
    LogManager(std::shared_ptr<Configuration> config);
    void processMessage(std::shared_ptr<MessageAbstract> message);

    void registerLogHandler(std::shared_ptr<LogHandlerAbstract> handler);
    std::list<std::shared_ptr<LogHandlerAbstract>> getLogHandlers();

protected:
    std::shared_ptr<Configuration> config;

private:
    std::list<std::shared_ptr<LogHandlerAbstract>> logHandlers;
};


#endif //DYALOG_LOGMANAGER_H
