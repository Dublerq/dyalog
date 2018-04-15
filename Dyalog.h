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

    void log(std::shared_ptr<MessageAbstract> message, std::string file = __FILE__, std::string function = __PRETTY_FUNCTION__, int fileLine = __LINE__);
    void logAdditionalInfo(std::shared_ptr<MessageAbstract> message, std::string file, std::string function, int fileLine);
private:
    std::unique_ptr<LogManager> logManager;
    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_DYALOG_H
