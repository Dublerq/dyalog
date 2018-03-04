#ifndef DYALOG_LOGQUEUE_H
#define DYALOG_LOGQUEUE_H

#include <list>
#include "MessageAbstract.h"

class LogQueue {

public:
    void pushMessage(std::shared_ptr<MessageAbstract> message);
    std::shared_ptr<MessageAbstract> popMessage();
    unsigned long size();

private:
    std::list<std::shared_ptr<MessageAbstract>> messages;
};


#endif //DYALOG_LOGQUEUE_H
