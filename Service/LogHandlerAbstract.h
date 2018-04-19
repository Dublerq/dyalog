#ifndef DYALOG_LOGHANDLERABSTRACT_H
#define DYALOG_LOGHANDLERABSTRACT_H


#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"
#include "../Helper/MessageFormatterAbstract.h"

/**
 * @brief Abstract class to be implemented by all log handlers
 */
class LogHandlerAbstract {
public:
    LogHandlerAbstract(unsigned int loggedLevelFrom, unsigned int loggedLevelTo);

    /**
     * @brief Check logging levels and conditionally handle further message processing
     * @param message model
     */
    virtual void processMessage(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Inject handler configuration
     * @param config model
     */
    void setConfiguration(std::shared_ptr<Configuration> config) {
        this->config = config;
    }

    /**
     * @brief Set formatter for the message
     * @param formatter
     */
    void setFormatter(std::shared_ptr<MessageFormatterAbstract> formatter);

    /**
     * @brief Initialize handler if needed
     */
    virtual void initHandler() {};

protected:
    /**
     * @brief Check if handler should process the message
     * @param message model
     */
    virtual bool canExecute(std::shared_ptr<MessageAbstract> message);

    /**
     * @brief Process the log
     * @param message model
     */
    virtual void execute(std::shared_ptr<MessageAbstract> message) = 0;

    /**
     * @brief Get formatted message as text ready to be logged
     * @param message model
     * @return formatted text
     */
    std::string getFinalMessage(std::shared_ptr<MessageAbstract> message);

    std::shared_ptr<Configuration> config;
    std::shared_ptr<MessageFormatterAbstract> formatter;
    unsigned int loggedLevelFrom = 0;
    unsigned int loggedLevelTo = 9999;
};


#endif //DYALOG_LOGHANDLERABSTRACT_H
