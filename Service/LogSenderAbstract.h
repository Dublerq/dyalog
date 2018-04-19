#ifndef DYALOG_LOGSENDERABSTRACT_H
#define DYALOG_LOGSENDERABSTRACT_H

#include <memory>
#include "LogHandlerAbstract.h"
#include "../Model/MessageAbstract.h"

/**
 * Abstract class to extend by remote log senders
 */
class LogSenderAbstract : public LogHandlerAbstract {

public:
    LogSenderAbstract(unsigned int loggedLevelFrom, unsigned int loggedLevelTo);


protected:
    /// @inherit
    void execute(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Send Message to remote server
     * @param message model
     */
    virtual void sendMessage(std::shared_ptr<MessageAbstract> message) = 0;

    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_LOGSENDERABSTRACT_H
