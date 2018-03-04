#ifndef DYALOG_ERRORMESSAGE_H
#define DYALOG_ERRORMESSAGE_H

#include "../MessageAbstract.h"

class ErrorMessage : public MessageAbstract {

public:
    std::unique_ptr<MessageLevelAbstract> getMessageLevel();
};


#endif //DYALOG_ERRORMESSAGE_H
