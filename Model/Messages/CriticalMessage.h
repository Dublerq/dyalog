#ifndef DYALOG_CRITICALMESSAGE_H
#define DYALOG_CRITICALMESSAGE_H

#include "../MessageAbstract.h"

class CriticalMessage : public MessageAbstract {

public:
    std::string getMessageType() final { return "Critical"; };
    unsigned int getMessageLevel() final { return 500; };
};


#endif //DYALOG_CRITICALMESSAGE_H
