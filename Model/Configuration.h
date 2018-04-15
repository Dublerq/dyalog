#ifndef DYALOG_CONFIGURATION_H
#define DYALOG_CONFIGURATION_H

class Configuration {
public:
    bool isCodeTraceLogged() const;
    void setCodeTraceLogged(bool codeTraceLogged);

private:
    bool codeTraceLogged;
};


#endif //DYALOG_CONFIGURATION_H
