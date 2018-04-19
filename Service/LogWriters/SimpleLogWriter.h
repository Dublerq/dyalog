#ifndef DYALOG_SIMPLELOGWRITER_H
#define DYALOG_SIMPLELOGWRITER_H

#include "../LogWriterAbstract.h"
#include "../../Helper/MessageFormatterAbstract.h"

class SimpleLogWriter : public LogWriterAbstract{

public:
    SimpleLogWriter(std::string filePath, unsigned int loggedLevelFrom = 0, unsigned int loggedLevelTo = 9999);

protected:
    void logMessage(std::shared_ptr<MessageAbstract> message);
    void writeMessage(std::string message);

private:
    std::string filePath;
};


#endif //DYALOG_SIMPLELOGWRITER_H
