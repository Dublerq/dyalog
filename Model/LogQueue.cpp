#include "LogQueue.h"

void LogQueue::pushMessage(std::shared_ptr<MessageAbstract> message) {
    this->messages.push_back(message);
}

std::shared_ptr<MessageAbstract> LogQueue::popMessage() {
    if (this->messages.empty()) {
        return std::shared_ptr<MessageAbstract>();
    } else {
        auto message = this->messages.front();
        this->messages.pop_front();
        return message;
    }
}
