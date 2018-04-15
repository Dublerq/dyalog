#ifndef DYALOG_MESSAGEFORMATTERABSTRACT_H
#define DYALOG_MESSAGEFORMATTERABSTRACT_H


#include "../Model/MessageAbstract.h"

class MessageFormatterAbstract {
public:
    virtual std::string getFormattedMessage(std::shared_ptr<MessageAbstract> message) = 0;
};


#endif //DYALOG_MESSAGEFORMATTERABSTRACT_H
