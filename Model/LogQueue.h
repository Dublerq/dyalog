#ifndef DYALOG_LOGQUEUE_H
#define DYALOG_LOGQUEUE_H

#include <list>
#include "MessageAbstract.h"

/**
 * @brief Basic list-based queue for managing messages to process
 */
class LogQueue {

public:
    /**
     * @brief Add message to que
     * @param message model
     */
    void pushMessage(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Return first message from the queue and remove it
     * @return message model
     */
    std::shared_ptr<MessageAbstract> popMessage();

    /**
     * @brief Get amount of messages in the queue
     * @return number of queued messages
     */
    unsigned long size() { return this->messages.size(); };

private:
    std::list<std::shared_ptr<MessageAbstract>> messages;
};


#endif //DYALOG_LOGQUEUE_H
