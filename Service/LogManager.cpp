#include "LogManager.h"

LogManager::LogManager(std::shared_ptr<Configuration> config) {
    this->config = config;
}

void LogManager::processMessage(std::shared_ptr<MessageAbstract> message) {
    for (auto handler : this->logHandlers){
        handler->processMessage(message);
    }
}

std::list<std::shared_ptr<LogHandlerAbstract>> LogManager::getLogHandlers() {
    return this->logHandlers;
}

void LogManager::registerLogHandler(std::shared_ptr<LogHandlerAbstract> handler) {
    handler->setConfiguration(this->config);
    this->logHandlers.push_back(handler);
}
