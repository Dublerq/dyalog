#include "ErrorMessage.h"
#include "../MessageLevels/ErrorMessageLevel.h"

std::unique_ptr<MessageLevelAbstract> ErrorMessage::getMessageLevel() {
    return std::unique_ptr<ErrorMessageLevel>( new ErrorMessageLevel());
}
