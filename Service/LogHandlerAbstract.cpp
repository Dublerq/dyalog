#include "LogHandlerAbstract.h"

void LogHandlerAbstract::processMessage(std::shared_ptr <MessageAbstract> message) {
    if (this->canExecute(message)) {
        this->execute(message);
    }
}

bool LogHandlerAbstract::canExecute(std::shared_ptr<MessageAbstract> message) {
    return message->getMessageLevel() >= loggedLevel;
}