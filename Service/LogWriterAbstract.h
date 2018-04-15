#ifndef DYALOG_LOGWRITERABSTRACT_H
#define DYALOG_LOGWRITERABSTRACT_H


#include <memory>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "LogHandlerAbstract.h"

class LogWriterAbstract : public LogHandlerAbstract{

public:
    void execute(std::shared_ptr<MessageAbstract> message);

protected:
    virtual void logMessage(std::shared_ptr<MessageAbstract> shared_ptr) = 0;

    unsigned int loggedLevel = 0;
};


#endif //DYALOG_LOGWRITERABSTRACT_H
