#ifndef DYALOG_DYALOG_H
#define DYALOG_DYALOG_H

#include <memory>
#include "Service/LogHandlerAbstract.h"
#include "Service/LogManager.h"
#include "Model/Configuration.h"

class Dyalog {

public:
    Dyalog();
    void registerLogHandler(std::shared_ptr<LogHandlerAbstract> handler);
    void log(std::shared_ptr<MessageAbstract> message, std::string file = __builtin_FILE(), std::string function = __builtin_FUNCTION(), int fileLine = __builtin_LINE());
    std::shared_ptr<Configuration> getConfig() { return this->config; }

private:
    void logAdditionalInfo(std::shared_ptr<MessageAbstract> message, std::string file, std::string function, int fileLine);
    std::unique_ptr<LogManager> logManager;
    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_DYALOG_H
