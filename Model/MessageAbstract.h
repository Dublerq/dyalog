#ifndef DYALOG_MESSAGEABSTRACT_H
#define DYALOG_MESSAGEABSTRACT_H

#include <string>
#include <memory>
#include <sstream>
#include <chrono>

/**
 * @brief Model that contains information about content to be logged
 */
class MessageAbstract {

public:
    /**
     * @brief Get unformatted information to be logged
     * @return text message
     */
    std::string getMessage(){
        return message;
    };

    /**
     * @brief Set raw information to be logged
     * @tparam T stringstream compatible type
     * @param message stringstream compatible object
     */
    template <typename T>
    void setMessage(T message){
        std::stringstream stringStream;
        stringStream << message;

        this->message = stringStream.str();
    }

    /**
     * @brief Set code references
     * @param file path
     * @param function name
     * @param fileLine in the source file
     */
    void setCodeTrace(std::string file, std::string function, int fileLine);

    /**
     * @brief Get log source file path
     * @return file path
     */
    std::string getFile() const {
        return this->file;
    }

    /**
     * @brief Get log source function name
     * @return function name
     */
    std::string getFunction() const {
        return this->function;
    }

    /**
     * @brief Get log source file line
     * @return file line
     */
    int getFileLine() const {
        return this->fileLine;
    }

    /**
     * @brief Set time when the log processing started
     * @param timePoint of message processing start
     */
    void setTime(std::chrono::time_point<std::chrono::system_clock> timePoint) {
        this->time = timePoint;
    }

    /**
     * @brief Get time when the log processing started
     * @return time point of message processing start
     */
    std::chrono::time_point<std::chrono::system_clock> getTime() const {
        return this->time;
    }

    /**
     * @brief Get message type caption
     * @return message caption
     */
    virtual std::string getMessageType() {
        return "";
    };

    /**
     * @brief Get message level of priority
     * @return message level of priority
     */
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
