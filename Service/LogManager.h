#ifndef DYALOG_LOGMANAGER_H
#define DYALOG_LOGMANAGER_H


#include <memory>
#include <list>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "LogHandlerAbstract.h"
#include "../Helper/MessageFormatters/BasicMessageFormatter.h"

/**
 * Log handlers registry and dispatcher
 */
class LogManager {

public:
    LogManager(std::shared_ptr<Configuration> config);

    /**
     * @brief Handle message logging by dispatching in registered handlers.
     * @param message
     */
    void processMessage(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Register log handler for log processing
     * @tparam Formatter instance derived from MessageFormatterAbstract
     * @param handler
     */
    template <class Formatter = BasicMessageFormatter>
    void registerLogHandler(std::shared_ptr<LogHandlerAbstract> handler) {
        std::shared_ptr<Formatter> formatterInstance (new Formatter(this->config));
        handler->setFormatter(formatterInstance);
        handler->setConfiguration(this->config);
        handler->initHandler();
        this->logHandlers.push_back(handler);
    }

    /**
     * @brief Get all registered log handlers
     * @return log handlers
     */
    std::list<std::shared_ptr<LogHandlerAbstract>> getLogHandlers();

private:
    std::shared_ptr<Configuration> config;
    std::list<std::shared_ptr<LogHandlerAbstract>> logHandlers;
};


#endif //DYALOG_LOGMANAGER_H
