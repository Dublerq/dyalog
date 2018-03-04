#ifndef DYALOG_CRITICALMESSAGE_H
#define DYALOG_CRITICALMESSAGE_H

#include "../MessageAbstract.h"

class CriticalMessage : public MessageAbstract {

public:
    std::unique_ptr<MessageLevelAbstract> getMessageLevel();
};


#endif //DYALOG_CRITICALMESSAGE_H
