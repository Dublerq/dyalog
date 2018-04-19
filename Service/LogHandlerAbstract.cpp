#include "LogHandlerAbstract.h"
#include <utility>

LogHandlerAbstract::LogHandlerAbstract(unsigned int loggedLevelFrom, unsigned int loggedLevelTo)
        : loggedLevelFrom(loggedLevelFrom),
          loggedLevelTo(loggedLevelTo)
{

}

void LogHandlerAbstract::processMessage(std::shared_ptr <MessageAbstract> message) {
    if (this->canExecute(message)) {
        this->execute(message);
    }
}

bool LogHandlerAbstract::canExecute(std::shared_ptr<MessageAbstract> message) {
    return message->getMessageLevel() >= loggedLevelFrom && message->getMessageLevel() <= loggedLevelTo;
}

void LogHandlerAbstract::setFormatter(std::shared_ptr<MessageFormatterAbstract> formatter) {
    this->formatter = std::move(formatter);
}

std::string LogHandlerAbstract::getFinalMessage(std::shared_ptr<MessageAbstract> message) {
    if (this->formatter != nullptr){
        return this->formatter->getFormattedMessage(message);
    } else {
        return message->getMessage();
    }
}
