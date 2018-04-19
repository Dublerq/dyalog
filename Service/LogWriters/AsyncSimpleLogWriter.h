#ifndef DYALOG_ASYNCSIMPLELOGWRITER_H
#define DYALOG_ASYNCSIMPLELOGWRITER_H

#include "../LogWriterAbstract.h"
#include "../../Helper/MessageFormatterAbstract.h"
#include "../../Model/LogQueue.h"

class AsyncSimpleLogWriter : public LogWriterAbstract{

public:
    AsyncSimpleLogWriter(std::string filePath, unsigned int awaitPeriod = 1000, unsigned int loggedLevelFrom = 0, unsigned int loggedLevelTo = 9999);
    void initHandler();
    void stopWorker() { this->workerRunning = false; }

protected:
    void logMessage(std::shared_ptr<MessageAbstract> message);
    void logMessageAsync(std::shared_ptr<MessageAbstract> message, std::ofstream &ofs);
    void writeMessageAsync(std::string message, std::ofstream &ofs);
    void worker();

private:
    std::string filePath;
    std::unique_ptr<LogQueue> queue;
    bool workerRunning = true;
    unsigned int awaitPeriod;
};


#endif //DYALOG_ASYNCSIMPLELOGWRITER_H
