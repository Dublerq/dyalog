#include <fstream>
#include <thread>
#include "AsyncSimpleLogWriter.h"

AsyncSimpleLogWriter::AsyncSimpleLogWriter(std::string filePath) {
    this->filePath = filePath;
    this->queue = std::unique_ptr<LogQueue>(new LogQueue());
}

void AsyncSimpleLogWriter::logMessage(std::shared_ptr<MessageAbstract> message) {
    this->queue->pushMessage(std::move(message));
}

void AsyncSimpleLogWriter::logMessageAsync(std::shared_ptr<MessageAbstract> message, std::ofstream &ofs) {
    std::string finalMessage = "";

    if (this->formatter != NULL){
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

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void AsyncSimpleLogWriter::writeMessageAsync(std::string message, std::ofstream &ofs) {
    ofs << message;
}
