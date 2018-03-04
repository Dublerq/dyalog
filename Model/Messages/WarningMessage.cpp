#include "WarningMessage.h"
#include "../MessageLevels/WarningMessageLevel.h"

std::unique_ptr<MessageLevelAbstract> WarningMessage::getMessageLevel() {
    return std::unique_ptr<WarningMessageLevel>( new WarningMessageLevel());
}
