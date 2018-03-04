#include "CriticalMessage.h"
#include "../MessageLevels/CriticalMessageLevel.h"

std::unique_ptr<MessageLevelAbstract> CriticalMessage::getMessageLevel() {
    return std::unique_ptr<CriticalMessageLevel>( new CriticalMessageLevel());
}
