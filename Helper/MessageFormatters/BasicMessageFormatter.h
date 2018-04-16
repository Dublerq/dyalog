#ifndef DYALOG_BASICMESSAGEFORMATTER_H
#define DYALOG_BASICMESSAGEFORMATTER_H

#include "../MessageFormatterAbstract.h"

class BasicMessageFormatter : public MessageFormatterAbstract {
public:
    BasicMessageFormatter(const std::shared_ptr<Configuration> &config);
    std::string getFormattedMessage(std::shared_ptr<MessageAbstract> message);
};


#endif //DYALOG_BASICMESSAGEFORMATTER_H
