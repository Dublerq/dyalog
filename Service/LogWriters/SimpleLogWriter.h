#ifndef DYALOG_SIMPLELOGWRITER_H
#define DYALOG_SIMPLELOGWRITER_H

#include "../LogWriterAbstract.h"
#include "../../Helper/MessageFormatterAbstract.h"

/**
 * @brief Basic write handler to open file and save a message every time it's processed
 */
class SimpleLogWriter : public LogWriterAbstract{

public:
    SimpleLogWriter(std::string filePath, unsigned int loggedLevelFrom = 0, unsigned int loggedLevelTo = 9999);

protected:
    /// @inherit
    void logMessage(std::shared_ptr<MessageAbstract> message);
    /**
     * @brief open selected file and append the log message
     * @param message text to be saved into file
     */
    void writeMessage(std::string message);

private:
    std::string filePath;
};


#endif //DYALOG_SIMPLELOGWRITER_H
