#include <fstream>
#include "SimpleLogWriter.h"

SimpleLogWriter::SimpleLogWriter(std::string filePath, unsigned int loggedLevelFrom, unsigned int loggedLevelTo) : LogWriterAbstract(loggedLevelFrom, loggedLevelTo) {
    this->filePath = filePath;
}

void SimpleLogWriter::logMessage(std::shared_ptr<MessageAbstract> message) {
    this->writeMessage(this->getFinalMessage(message));
}

void SimpleLogWriter::writeMessage(std::string message) {
    std::ofstream ofs;
    ofs.open (filePath, std::ofstream::out | std::ofstream::app);

    ofs << message;

    ofs.close();
}
