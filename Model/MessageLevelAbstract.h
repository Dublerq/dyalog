#ifndef DYALOG_MESSAGELEVELABSTRACT_H
#define DYALOG_MESSAGELEVELABSTRACT_H

#include <string>

class MessageLevelAbstract {

    public:
        virtual std::string getLevelCaption() const = 0;
        virtual unsigned int getLevelValue() const = 0;
};


#endif //DYALOG_MESSAGELEVELABSTRACT_H
