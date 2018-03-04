#ifndef DYALOG_DEBUGMESSAGE_H
#define DYALOG_DEBUGMESSAGE_H

#include "../MessageAbstract.h"

class DebugMessage : public MessageAbstract {

public:
    std::unique_ptr<MessageLevelAbstract> getMessageLevel();
};


#endif //DYALOG_DEBUGMESSAGE_H
