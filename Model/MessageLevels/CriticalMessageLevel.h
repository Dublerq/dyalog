#ifndef DYALOG_CRITICALMESSAGELEVEL_H
#define DYALOG_CRITICALMESSAGELEVEL_H

#include "../MessageLevelAbstract.h"

class CriticalMessageLevel : public MessageLevelAbstract {

public:
    std::string getLevelCaption() const {
        return "critical";
    };

    unsigned int getLevelValue() const {
        return 500;
    };
};


#endif //DYALOG_CRITICALMESSAGELEVEL_H
