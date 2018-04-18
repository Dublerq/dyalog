#ifndef DYALOG_LOGSENDERABSTRACT_H
#define DYALOG_LOGSENDERABSTRACT_H

#include <memory>
#include "LogHandlerAbstract.h"
#include "../Model/MessageAbstract.h"

class LogSenderAbstract : public LogHandlerAbstract {

public:
    void execute(std::shared_ptr<MessageAbstract> message);

protected:
    virtual void sendMessage(std::shared_ptr<MessageAbstract> shared_ptr) = 0;
    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_LOGSENDERABSTRACT_H
