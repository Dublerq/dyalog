#ifndef DYALOG_DEBUGMESSAGELEVEL_H
#define DYALOG_DEBUGMESSAGELEVEL_H

#include "../MessageLevelAbstract.h"

class DebugMessageLevel : public MessageLevelAbstract {

public:
    std::string getLevelCaption() const {
        return "debug";
    };

    unsigned int getLevelValue() const {
        return 100;
    };
};


#endif //DYALOG_DEBUGMESSAGELEVEL_H
