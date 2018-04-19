#ifndef DYALOG_NOTICEMESSAGE_H
#define DYALOG_NOTICEMESSAGE_H

#include "../MessageAbstract.h"
/**
 * @inherit
 */
class NoticeMessage : public MessageAbstract {

public:
    /// @inherit
    std::string getMessageType() final { return "Notice"; };
    /// @inherit
    unsigned int getMessageLevel() final { return 200; };
};


#endif //DYALOG_NOTICEMESSAGE_H
