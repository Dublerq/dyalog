#ifndef DYALOG_LOGWRITERABSTRACT_H
#define DYALOG_LOGWRITERABSTRACT_H


#include <memory>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "LogHandlerAbstract.h"
#include "../Helper/MessageFormatterAbstract.h"

class LogWriterAbstract : public LogHandlerAbstract{

public:
    LogWriterAbstract(unsigned int loggedLevelFrom, unsigned int loggedLevelTo);

protected:
    /// @inherit
    virtual void execute(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Process message and save to file
     * @param message
     */
    virtual void logMessage(std::shared_ptr<MessageAbstract> message) = 0;

    unsigned int loggedLevel = 0;
};


#endif //DYALOG_LOGWRITERABSTRACT_H
