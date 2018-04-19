#ifndef DYALOG_CONFIGURATION_H
#define DYALOG_CONFIGURATION_H

/**
 * @brief Container storing configuration, injected to handlers in order to manage log processing
 */
class Configuration {
public:
    /**
     * @brief Check if logs should contain references to code
     */
    bool isCodeTraceLogged() const;

    /**
     * @brief Set if logs should contain references to code
     */
    void setCodeTraceLogged(bool codeTraceLogged);

private:
    bool codeTraceLogged;
};


#endif //DYALOG_CONFIGURATION_H
