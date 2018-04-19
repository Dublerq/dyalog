#ifndef DYALOG_ERRORMESSAGE_H
#define DYALOG_ERRORMESSAGE_H

#include "../MessageAbstract.h"

/**
 * @inherit
 */
class ErrorMessage : public MessageAbstract {

public:
    /// @inherit
    std::string getMessageType() final { return "Error"; };
    /// @inherit
    unsigned int getMessageLevel() final { return 400; };
};

#endif //DYALOG_ERRORMESSAGE_H
