#ifndef DYALOG_CONSOLELOGGER_H
#define DYALOG_CONSOLELOGGER_H

#include "LogHandlerAbstract.h"

/**
 * @brief Display logged message in the terminal
 */
class ConsoleLogger : public LogHandlerAbstract {
public:
    ConsoleLogger(unsigned int loggedLevelFrom = 0, unsigned int loggedLevelTo = 9999);

    /// @inherit
    void execute(std::shared_ptr<MessageAbstract> message);
};


#endif //DYALOG_CONSOLELOGGER_H
