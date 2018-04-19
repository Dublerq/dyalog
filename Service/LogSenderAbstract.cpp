#include "LogSenderAbstract.h"

void LogSenderAbstract::execute(std::shared_ptr<MessageAbstract> message) {
    this->sendMessage(message);
}

LogSenderAbstract::LogSenderAbstract(unsigned int loggedLevelFrom, unsigned int loggedLevelTo)
        : LogHandlerAbstract(loggedLevelFrom, loggedLevelTo)
{

}
