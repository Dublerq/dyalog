#ifndef DYALOG_DYALOG_H
#define DYALOG_DYALOG_H

#include <memory>
#include "Service/LogWriterAbstract.h"
#include "Service/LogSenderAbstract.h"
#include "Service/LogManager.h"
#include "Model/Configuration.h"

class Dyalog {

public:
    Dyalog();

    void addWriter(std::shared_ptr<LogWriterAbstract> writer);
    void addSender(std::shared_ptr<LogSenderAbstract> sender);

    void log(std::shared_ptr<MessageAbstract> message);

private:
    std::unique_ptr<LogManager> logManager;
    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_DYALOG_H
