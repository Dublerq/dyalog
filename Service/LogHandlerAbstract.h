#ifndef DYALOG_LOGHANDLERABSTRACT_H
#define DYALOG_LOGHANDLERABSTRACT_H


#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "../Helper/MessageFormatterAbstract.h"

class LogHandlerAbstract {
public:
    virtual void processMessage(std::shared_ptr<MessageAbstract> message);
    void setConfiguration(std::shared_ptr<Configuration> config) {
        this->config = config;
    }
    void setFormatter(std::shared_ptr<MessageFormatterAbstract> formatter);
    virtual void initHandler() {};

protected:
    virtual bool canExecute(std::shared_ptr<MessageAbstract> message);
    virtual void execute(std::shared_ptr<MessageAbstract> message) = 0;

    std::shared_ptr<Configuration> config;
    std::shared_ptr<MessageFormatterAbstract> formatter;
    unsigned int loggedLevel = 0;
};


#endif //DYALOG_LOGHANDLERABSTRACT_H
