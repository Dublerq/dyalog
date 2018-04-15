#include "Dyalog.h"

Dyalog::Dyalog() {
    this->config = std::make_shared<Configuration>();
    this->logManager = std::unique_ptr<LogManager>(new LogManager(this->config));
}

void Dyalog::registerLogHandler(std::shared_ptr<LogHandlerAbstract> handler) {
    this->logManager->registerLogHandler(handler);
}

void Dyalog::log(std::shared_ptr<MessageAbstract> message, std::string file, std::string function, int fileLine) {
    this->logAdditionalInfo(message, file, function, fileLine);
    this->logManager->processMessage(message);
}

void Dyalog::logAdditionalInfo(std::shared_ptr<MessageAbstract> message, std::string file, std::string function, int fileLine) {
    if (this->config->isCodeTraceLogged()) {
        message->setCodeTrace(std::move(file), std::move(function), fileLine);
    }
}