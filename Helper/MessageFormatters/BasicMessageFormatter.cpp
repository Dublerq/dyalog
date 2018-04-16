#include "BasicMessageFormatter.h"
#include "../../lib/date.h"

BasicMessageFormatter::BasicMessageFormatter(const std::shared_ptr<Configuration> &config) : MessageFormatterAbstract(
        config) {

}

std::string BasicMessageFormatter::getFormattedMessage(std::shared_ptr<MessageAbstract> message) {
    std::string finalMessage = "";

    std::string datetime = date::format("%F %T", std::chrono::system_clock::now());

    finalMessage += "[" + datetime + "] ";
    finalMessage += message->getMessageType() + ": ";
    finalMessage += message->getMessage();

    if (this->config->isCodeTraceLogged()){
        finalMessage += " [at " + message->getFile() + ":" + std::to_string(message->getFileLine()) + "::" + message->getFunction() + "(...)]";
    }
    finalMessage += "\n";
    return finalMessage;
}
