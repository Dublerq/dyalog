#ifndef DYALOG_MESSAGEABSTRACT_H
#define DYALOG_MESSAGEABSTRACT_H

#include <string>
#include <memory>
#include <sstream>
#include <chrono>

class MessageAbstract {

public:
    std::string getMessage(){
        return message;
    };

    template <typename T>
    void setMessage(T message){
        std::stringstream stringStream;
        stringStream << message;

        this->message = stringStream.str();
    }

    void setCodeTrace(std::string file, std::string function, int fileLine);

    std::string getFile() const {
        return this->file;
    }

    std::string getFunction() const {
        return this->function;
    }

    int getFileLine() const {
        return this->fileLine;
    }

    void setTime(std::chrono::time_point<std::chrono::system_clock> timePoint) {
        this->time = timePoint;
    }

    std::chrono::time_point<std::chrono::system_clock> getTime() const {
        return this->time;
    }

    virtual std::string getMessageType() {
        return "";
    };

    virtual unsigned int getMessageLevel() {
        return 0;
    };



protected:
    std::string message;
    std::string file;
    std::string function;
    std::chrono::time_point<std::chrono::system_clock> time;
    int fileLine;
};

#endif //DYALOG_MESSAGEABSTRACT_H
