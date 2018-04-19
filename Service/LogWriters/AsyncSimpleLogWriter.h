#ifndef DYALOG_ASYNCSIMPLELOGWRITER_H
#define DYALOG_ASYNCSIMPLELOGWRITER_H

#include "../LogWriterAbstract.h"
#include "../../Helper/MessageFormatterAbstract.h"
#include "../../Model/LogQueue.h"

/**
 * @brief Write handler to open file asynchronously and save messages in regular sessions separated by await period
 */
class AsyncSimpleLogWriter : public LogWriterAbstract{

public:
    /**
     * @param filePath to the target file
     * @param awaitPeriod in ms
     * @param loggedLevelFrom minimal log level
     * @param loggedLevelTo maxmial log level
     */
    AsyncSimpleLogWriter(std::string filePath, unsigned int awaitPeriod = 1000, unsigned int loggedLevelFrom = 0, unsigned int loggedLevelTo = 9999);

    /// @inherit
    void initHandler();

    /**
     * @brief Method allowing to stop worker
     */
    void stopWorker() { this->workerRunning = false; }

protected:
    /// @inherit
    void logMessage(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Pepares and writes a log from async worker to the target file over opend file stream
     * @param message model
     */
    void logMessageAsync(std::shared_ptr<MessageAbstract> message, std::ofstream &ofs);

    /**
     * @brief Writes a log from async worker to the target file over opend file stream
     * @param message model
     */
    void writeMessageAsync(std::string message, std::ofstream &ofs);

    /**
     * @brief Async thread worker running forever unless application is closed or stopWorker method was performed
     * Writes queued logs in equally separated by the tim sessions
     */
    void worker();

private:
    std::string filePath;
    std::unique_ptr<LogQueue> queue;
    bool workerRunning = true;
    unsigned int awaitPeriod;
};


#endif //DYALOG_ASYNCSIMPLELOGWRITER_H
