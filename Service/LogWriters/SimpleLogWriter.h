#ifndef DYALOG_SIMPLELOGWRITER_H
#define DYALOG_SIMPLELOGWRITER_H

#include "../LogWriterAbstract.h"
#include "../../Helper/MessageFormatterAbstract.h"

class SimpleLogWriter : public LogWriterAbstract{

public:
    SimpleLogWriter(std::string filePath);

protected:
    void logMessage(std::shared_ptr<MessageAbstract> shared_ptr);
    void writeMessage(std::string message);

private:
    std::string filePath;
};


#endif //DYALOG_SIMPLELOGWRITER_H
