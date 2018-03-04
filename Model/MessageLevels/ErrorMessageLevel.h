#ifndef DYALOG_ERRORMESSAGELEVEL_H
#define DYALOG_ERRORMESSAGELEVEL_H

#include "../MessageLevelAbstract.h"

class ErrorMessageLevel : public MessageLevelAbstract {

public:
    std::string getLevelCaption() const {
        return "error";
    };

    unsigned int getLevelValue() const {
        return 400;
    };
};


#endif //DYALOG_ERRORMESSAGELEVEL_H
