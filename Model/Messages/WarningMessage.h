#ifndef DYALOG_WARNINGMESSAGE_H
#define DYALOG_WARNINGMESSAGE_H

#include "../MessageAbstract.h"

class WarningMessage : public MessageAbstract {

public:
    std::string getMessageType() final { return "Warning"; };
    unsigned int getMessageLevel() final { return 300; };
};


#endif //DYALOG_WARNINGMESSAGE_H
