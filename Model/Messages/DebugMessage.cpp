#include "DebugMessage.h"
#include "../MessageLevels/DebugMessageLevel.h"

std::unique_ptr<MessageLevelAbstract> DebugMessage::getMessageLevel() {
    return std::unique_ptr<DebugMessageLevel>( new DebugMessageLevel());
}
