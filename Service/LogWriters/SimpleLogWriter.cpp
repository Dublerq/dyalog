#include <fstream>
#include "SimpleLogWriter.h"

SimpleLogWriter::SimpleLogWriter(std::string filePath) {
    this->filePath = filePath;
}

void SimpleLogWriter::logMessage(std::shared_ptr<MessageAbstract> message) {
    std::string finalMessage = "";
    if (this->formatter != NULL){
        finalMessage = this->formatter->getFormattedMessage(message);
    } else {
        finalMessage = message->getMessage();
    }
    this->writeMessage(finalMessage);
}

void SimpleLogWriter::writeMessage(std::string message) {
    std::ofstream ofs;
    ofs.open (filePath, std::ofstream::out | std::ofstream::app);

    ofs << message;

    ofs.close();
}
