#ifndef DYALOG_DEBUGMESSAGE_H
#define DYALOG_DEBUGMESSAGE_H

#include "../MessageAbstract.h"

class DebugMessage : public MessageAbstract {

public:
    std::string getMessageType() final { return "Debug"; };
    unsigned int getMessageLevel() final { return 100; };
};


#endif //DYALOG_DEBUGMESSAGE_H
