#ifndef DYALOG_NOTICEMESSAGE_H
#define DYALOG_NOTICEMESSAGE_H

#include "../MessageAbstract.h"

class NoticeMessage : public MessageAbstract {

public:
    std::unique_ptr<MessageLevelAbstract> getMessageLevel();
};


#endif //DYALOG_NOTICEMESSAGE_H
