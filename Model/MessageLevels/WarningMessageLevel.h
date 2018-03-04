#ifndef DYALOG_WARNINGMESSAGELEVEL_H
#define DYALOG_WARNINGMESSAGELEVEL_H

#include "../MessageLevelAbstract.h"

class WarningMessageLevel : public MessageLevelAbstract {

public:
    std::string getLevelCaption() const {
        return "warning";
    };

    unsigned int getLevelValue() const {
        return 300;
    };
};


#endif //DYALOG_WARNINGMESSAGELEVEL_H
