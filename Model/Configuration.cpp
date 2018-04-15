#include "Configuration.h"

bool Configuration::isCodeTraceLogged() const {
    return this->codeTraceLogged;
}

void Configuration::setCodeTraceLogged(bool codeTraceLogged) {
    this->codeTraceLogged = codeTraceLogged;
}