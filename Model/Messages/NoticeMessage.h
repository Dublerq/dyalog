#ifndef DYALOG_NOTICEMESSAGE_H
#define DYALOG_NOTICEMESSAGE_H

#include "../MessageAbstract.h"

class NoticeMessage : public MessageAbstract {

public:
    std::string getMessageType() final { return "Notice"; };
    unsigned int getMessageLevel() final { return 200; };
};


#endif //DYALOG_NOTICEMESSAGE_H
