#ifndef DYALOG_WARNINGMESSAGE_H
#define DYALOG_WARNINGMESSAGE_H

#include "../MessageAbstract.h"

/**
 * @inherit
 */
class WarningMessage : public MessageAbstract {

public:
    /// @inherit
    std::string getMessageType() final { return "Warning"; }
    /// @inherit
    unsigned int getMessageLevel() final { return 300; };
};


#endif //DYALOG_WARNINGMESSAGE_H
