#include <iostream>
#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger(unsigned int loggedLevelFrom, unsigned int loggedLevelTo)
        : LogHandlerAbstract(loggedLevelFrom, loggedLevelTo)
{

}

void ConsoleLogger::execute(std::shared_ptr<MessageAbstract> message) {
    std::cout << this->getFinalMessage(message);
}
