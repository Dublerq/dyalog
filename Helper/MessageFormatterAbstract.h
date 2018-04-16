#ifndef DYALOG_MESSAGEFORMATTERABSTRACT_H
#define DYALOG_MESSAGEFORMATTERABSTRACT_H


#include <utility>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"

class MessageFormatterAbstract {
public:
    MessageFormatterAbstract(std::shared_ptr<Configuration> config) : config(std::move(config)) {};
    virtual std::string getFormattedMessage(std::shared_ptr<MessageAbstract> message) = 0;

protected:
    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_MESSAGEFORMATTERABSTRACT_H
