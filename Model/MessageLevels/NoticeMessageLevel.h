#ifndef DYALOG_NOTICEMESSAGELEVEL_H
#define DYALOG_NOTICEMESSAGELEVEL_H

#include "../MessageLevelAbstract.h"

class NoticeMessageLevel : public MessageLevelAbstract {

public:
    std::string getLevelCaption() const {
        return "notice";
    };

    unsigned int getLevelValue() const {
        return 200;
    };
};


#endif //DYALOG_NOTICEMESSAGELEVEL_H
