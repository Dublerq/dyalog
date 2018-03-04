#include "NoticeMessage.h"
#include "../MessageLevels/NoticeMessageLevel.h"

std::unique_ptr<MessageLevelAbstract> NoticeMessage::getMessageLevel() {
    return std::unique_ptr<NoticeMessageLevel>( new NoticeMessageLevel());
}
