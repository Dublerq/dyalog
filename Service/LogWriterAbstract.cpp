#include "LogWriterAbstract.h"

void LogWriterAbstract::execute(std::shared_ptr<MessageAbstract> message) {
    this->logMessage(message);
}

LogWriterAbstract::LogWriterAbstract(unsigned int loggedLevelFrom, unsigned int loggedLevelTo)
        : LogHandlerAbstract(loggedLevelFrom, loggedLevelTo)
{

}
