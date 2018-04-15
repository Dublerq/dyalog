#ifndef DYALOG_ERRORMESSAGE_H
#define DYALOG_ERRORMESSAGE_H

#include "../MessageAbstract.h"

class ErrorMessage : public MessageAbstract {

public:
    std::string getMessageType() final { return "Error"; };
    unsigned int getMessageLevel() final { return 400; };
};

#endif //DYALOG_ERRORMESSAGE_H
