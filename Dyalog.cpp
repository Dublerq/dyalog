#include "Dyalog.h"

Dyalog::Dyalog() {
    this->config = std::make_shared<Configuration>();
    this->logManager = std::unique_ptr<LogManager>(new LogManager(this->config));
}

void Dyalog::addSender(std::shared_ptr<LogSenderAbstract> sender) {

}

void Dyalog::addWriter(std::shared_ptr<LogWriterAbstract> writer) {
    this->logManager->addWriter(writer);
}

void Dyalog::log(std::shared_ptr<MessageAbstract> message) {
    this->logManager->processMessage(message);
}
