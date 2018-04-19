#ifndef DYALOG_DEBUGMESSAGE_H
#define DYALOG_DEBUGMESSAGE_H

#include "../MessageAbstract.h"
/**
 * @inherit
 */
class DebugMessage : public MessageAbstract {

public:
    /// @inherit
    std::string getMessageType() final { return "Debug"; };
    /// @inherit
    unsigned int getMessageLevel() final { return 100; };
};


#endif //DYALOG_DEBUGMESSAGE_H
