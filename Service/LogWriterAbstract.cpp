#include "LogWriterAbstract.h"

void LogWriterAbstract::processMessage(std::shared_ptr<MessageAbstract> message) {
    if (message->getMessageLevel()->getLevelValue() < loggedLevel){
        return;
    }
    this->logMessage(message);
}

unsigned int LogWriterAbstract::getLoggedLevel() const {
    return loggedLevel;
}

void LogWriterAbstract::setLoggedLevel(unsigned int loggedLevel) {
    this->loggedLevel = loggedLevel;
}

void LogWriterAbstract::applyConfiguration(std::shared_ptr<Configuration> config) {
    this->config = config;
}
