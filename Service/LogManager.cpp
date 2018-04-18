#include "LogManager.h"

LogManager::LogManager(std::shared_ptr<Configuration> config) {
    this->config = config;
}

void LogManager::processMessage(std::shared_ptr<MessageAbstract> message) {
    message->setTime(std::chrono::system_clock::now());
    for (auto handler : this->logHandlers){
        handler->processMessage(message);
    }
}

std::list<std::shared_ptr<LogHandlerAbstract>> LogManager::getLogHandlers() {
    return this->logHandlers;
}