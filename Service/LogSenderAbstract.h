#ifndef DYALOG_LOGSENDERABSTRACT_H
#define DYALOG_LOGSENDERABSTRACT_H


#include <memory>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"

class LogSenderAbstract {

public:
    void processMessage(std::shared_ptr<MessageAbstract> message);
    unsigned int getLoggedLevel() const;
    void setLoggedLevel(unsigned int loggedLevel);
    void applyConfiguration(std::shared_ptr<Configuration> config);

protected:
    virtual void sendMessage(std::shared_ptr<MessageAbstract> shared_ptr) = 0;

    std::shared_ptr<Configuration> config;
    unsigned int loggedLevel;
};


#endif //DYALOG_LOGSENDERABSTRACT_H
