#ifndef DYALOG_CRITICALMESSAGE_H
#define DYALOG_CRITICALMESSAGE_H

#include "../MessageAbstract.h"

/**
 * @inherit
 */
class CriticalMessage : public MessageAbstract {

public:
    /// @inherit
    std::string getMessageType() final { return "Critical"; };
    /// @inherit
    unsigned int getMessageLevel() final { return 500; };
};


#endif //DYALOG_CRITICALMESSAGE_H
