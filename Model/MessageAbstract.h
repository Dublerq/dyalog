#ifndef DYALOG_MESSAGEABSTRACT_H
#define DYALOG_MESSAGEABSTRACT_H

#include <string>
#include <memory>
#include <sstream>
#include "MessageLevelAbstract.h"

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

    virtual std::unique_ptr<MessageLevelAbstract> getMessageLevel() = 0;



protected:

    std::string message;
};


#endif //DYALOG_MESSAGEABSTRACT_H
