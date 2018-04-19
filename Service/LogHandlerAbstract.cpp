#include "LogHandlerAbstract.h"
#include <utility>

LogHandlerAbstract::LogHandlerAbstract(unsigned int loggedLevel) : loggedLevel(loggedLevel) {

}

void LogHandlerAbstract::processMessage(std::shared_ptr <MessageAbstract> message) {
    if (this->canExecute(message)) {
        this->execute(message);
    }
}

bool LogHandlerAbstract::canExecute(std::shared_ptr<MessageAbstract> message) {
    return message->getMessageLevel() >= loggedLevel;
}

void LogHandlerAbstract::setFormatter(std::shared_ptr<MessageFormatterAbstract> formatter) {
    this->formatter = std::move(formatter);
}
