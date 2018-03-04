#ifndef DYALOG_LOGWRITERABSTRACT_H
#define DYALOG_LOGWRITERABSTRACT_H


#include <memory>
#include "../Model/MessageAbstract.h"
#include "../Model/Configuration.h"

class LogWriterAbstract {

public:
    void processMessage(std::shared_ptr<MessageAbstract> message);
    unsigned int getLoggedLevel() const;
    void setLoggedLevel(unsigned int loggedLevel);
    void applyConfiguration(std::shared_ptr<Configuration> config);

protected:
    virtual void logMessage(std::shared_ptr<MessageAbstract> shared_ptr) = 0;

    std::shared_ptr<Configuration> config;
    unsigned int loggedLevel = 0;
};


#endif //DYALOG_LOGWRITERABSTRACT_H
