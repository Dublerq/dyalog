#ifndef DYALOG_LOGMANAGER_H
#define DYALOG_LOGMANAGER_H


#include <memory>
#include <list>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "LogHandlerAbstract.h"
#include "../Helper/MessageFormatters/BasicMessageFormatter.h"

class LogManager {

public:
    LogManager(std::shared_ptr<Configuration> config);
    void processMessage(std::shared_ptr<MessageAbstract> message);

    template <class Formatter = BasicMessageFormatter>
    void registerLogHandler(std::shared_ptr<LogHandlerAbstract> handler) {
        std::shared_ptr<Formatter> formatterInstance (new Formatter(this->config));
        handler->setFormatter(formatterInstance);
        handler->setConfiguration(this->config);
        this->logHandlers.push_back(handler);
    }

    std::list<std::shared_ptr<LogHandlerAbstract>> getLogHandlers();

private:
    std::shared_ptr<Configuration> config;
    std::list<std::shared_ptr<LogHandlerAbstract>> logHandlers;
};


#endif //DYALOG_LOGMANAGER_H
