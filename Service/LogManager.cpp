#include "LogManager.h"

LogManager::LogManager(std::shared_ptr<Configuration> config) {
    this->config = config;
}

void LogManager::processMessage(std::shared_ptr<MessageAbstract> message) {
    for (auto writer : this->senders){
        writer->processMessage(message);
    }

    for (auto sender : this->senders){
        sender->processMessage(message);
    }
}

std::list<std::shared_ptr<LogWriterAbstract>> LogManager::getWriters() {
    return this->writers;
}

std::list<std::shared_ptr<LogSenderAbstract>> LogManager::getSenders() {
    return this->senders;
}

void LogManager::addWriter(std::shared_ptr<LogWriterAbstract> writer) {
    writer->applyConfiguration(this->config);
    this->writers.push_back(writer);
}

void LogManager::addSender(std::shared_ptr<LogSenderAbstract> sender) {
    sender->applyConfiguration(this->config);
    this->senders.push_back(sender);
}
