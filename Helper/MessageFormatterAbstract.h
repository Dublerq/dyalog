#ifndef DYALOG_MESSAGEFORMATTERABSTRACT_H
#define DYALOG_MESSAGEFORMATTERABSTRACT_H


#include <utility>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"

/**
 * @brief Helper class responsible for formatting Messsage models into final, log-ready strings
 */
class MessageFormatterAbstract {
public:
    MessageFormatterAbstract(std::shared_ptr<Configuration> config) : config(std::move(config)) {};

    /**
     * @brief Generate formatted string from message model
     * @param message model to be formatted
     * @return formatted, log-ready string message
     */
    virtual std::string getFormattedMessage(std::shared_ptr<MessageAbstract> message) = 0;

protected:
    std::shared_ptr<Configuration> config;
};


#endif //DYALOG_MESSAGEFORMATTERABSTRACT_H
