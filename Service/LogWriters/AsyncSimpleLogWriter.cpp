#include <fstream>
#include <thread>
#include <utility>
#include "AsyncSimpleLogWriter.h"

AsyncSimpleLogWriter::AsyncSimpleLogWriter(std::string filePath, unsigned int awaitPeriod, unsigned int loggedLevel)
        : LogWriterAbstract(loggedLevel)
{
    this->filePath = std::move(filePath);
    this->queue = std::unique_ptr<LogQueue>(new LogQueue());
    this->awaitPeriod = awaitPeriod;
}

void AsyncSimpleLogWriter::logMessage(std::shared_ptr<MessageAbstract> message) {
    this->queue->pushMessage(std::move(message));
}

void AsyncSimpleLogWriter::logMessageAsync(std::shared_ptr<MessageAbstract> message, std::ofstream &ofs) {
    std::string finalMessage;

    if (this->formatter != nullptr){
        finalMessage = this->formatter->getFormattedMessage(message);
    } else {
        finalMessage = message->getMessage();
    }

    this->writeMessageAsync(finalMessage, ofs);
}

void AsyncSimpleLogWriter::initHandler() {
    std::thread tWorker(&AsyncSimpleLogWriter::worker, this);
    tWorker.detach();
}

void AsyncSimpleLogWriter::worker() {
    std::ofstream ofs;

    while(workerRunning){
        ofs.open (filePath, std::ofstream::out | std::ofstream::app);
        while (auto message = this->queue->popMessage()) {
            this->logMessageAsync(message, ofs);
        }

        ofs.close();

        std::this_thread::sleep_for(std::chrono::milliseconds(this->awaitPeriod));
    }
}

void AsyncSimpleLogWriter::writeMessageAsync(std::string message, std::ofstream &ofs) {
    ofs << message;
}
