#ifndef DYALOG_BASICMESSAGEFORMATTER_H
#define DYALOG_BASICMESSAGEFORMATTER_H

#include "../MessageFormatterAbstract.h"

/**
 * @inherit
 */
class BasicMessageFormatter : public MessageFormatterAbstract {
public:
    BasicMessageFormatter(const std::shared_ptr<Configuration> &config);

    /**
     * @inherit
     */
    std::string getFormattedMessage(std::shared_ptr<MessageAbstract> message);
};


#endif //DYALOG_BASICMESSAGEFORMATTER_H
