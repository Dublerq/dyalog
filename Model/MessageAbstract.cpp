#include "MessageAbstract.h"

void MessageAbstract::setCodeTrace(std::string file, std::string function, int fileLine) {
    this->file = file;
    this->function = function;
    this->fileLine = fileLine;
}