#include "LogSenderAbstract.h"

void LogSenderAbstract::processMessage(std::shared_ptr<MessageAbstract> message) {
    if (message->getMessageLevel()->getLevelValue() < loggedLevel){
        return;
    }
    this->sendMessage(message);
}

unsigned int LogSenderAbstract::getLoggedLevel() const {
    return loggedLevel;
}

void LogSenderAbstract::setLoggedLevel(unsigned int loggedLevel) {
    this->loggedLevel = loggedLevel;
}

void LogSenderAbstract::applyConfiguration(std::shared_ptr<Configuration> config) {
    this->config = config;
}
