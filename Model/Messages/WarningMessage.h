#ifndef DYALOG_WARNINGMESSAGE_H
#define DYALOG_WARNINGMESSAGE_H

#include "../MessageAbstract.h"

class WarningMessage : public MessageAbstract {

public:
    std::unique_ptr<MessageLevelAbstract> getMessageLevel();
};


#endif //DYALOG_WARNINGMESSAGE_H
