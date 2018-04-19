#ifndef DYALOG_DYALOG_H
#define DYALOG_DYALOG_H

#include <memory>
#include "Service/LogHandlerAbstract.h"
#include "Service/LogManager.h"
#include "Model/Configuration.h"

/**
 * @brief Decent Yet Another LOGger library
 */
class Dyalog {

public:
    Dyalog();

    /**
     * @brief Register a log handler for processing logs
     * @param handler
     */
    void registerLogHandler(std::shared_ptr<LogHandlerAbstract> handler);

    /**
     * @brief Process a log
     * @param message model
     * @param file path, leave default to fill automatically
     * @param function name, leave default to fill automatically
     * @param fileLine number, leave default to fill automatically
     */
    void log(std::shared_ptr<MessageAbstract> message, std::string file = __builtin_FILE(), std::string function = __builtin_FUNCTION(), int fileLine = __builtin_LINE());
    std::shared_ptr<Configuration> getConfig() { return this->config; }

private:
    /**
     * Save message code tracking details
     * @param message model
     * @param file path, leave default to fill automatically
     * @param function name, leave default to fill automatically
     * @param fileLine number, leave default to fill automatically
     */
    void logAdditionalInfo(std::shared_ptr<MessageAbstract> message, std::string file, std::string function, int fileLine);
    std::unique_ptr<LogManager> logManager;
    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_DYALOG_H
