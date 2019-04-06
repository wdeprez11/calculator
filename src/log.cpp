#include "log.h"
#include <ctime>
#include <fstream>

/**
  * @brief Constructs a Message object
  * @param type The severity of the error 0 - Non-error, 1 - Non-fatal error, 2 - Fatal error
  * @param msg The string to store within the message
  */
Message::Message(int type, std::string msg)
    : msgType(type)
    , message(msg)
{
}

/**
  * @brief Gets the error type for logging and searching
  * @return Returns the error type for user reading.
  */
std::string Message::get_error_type()
{
    switch (msgType) {
    case 1:
        return "error: non-fatal";
        break;
    case 2:
        return "error: fatal";
        break;
    default:
        return "non-error";
        break;
    }
}

/**
  * @brief Gets the message for understanding what is happening in the code without debugging the code itself.
  * @return Returns the message associated with the error
  */
std::string Message::get_message()
{
    return message;
}

std::ofstream& Message::operator<<(std::ofstream stream, const Message& other)
{
    stream << other.message << '\n';
    //return stream;
}

/**
  * @brief Constructs a default Log object and initializes the output stream. Reserves space for 100 messages
  */
Log::Log()
    : reserved(100)
    , logFile("log.txt")
{
    set_start_time();
    //logFile.open(("log" + startTime).c_str());
    messageLog.reserve(reserved);
    emplace_back(Message(0, "Initializing Log..."));
    emplace_back(Message(0, "Log started at: " + std::string(startTime.c_str())));
    emplace_back(Message(0, "Waiting for user input..."));
}

/**
  * @brief Constructs a Log object and inherits an old log for continuation after a crash
  * @param oldLog The old log to inherit
  */
Log::Log(const Log& oldLog)
    : startTime(oldLog.startTime)
{
}

/**
  * @brief Closes the logFile and destroys the object.
  */
Log::~Log()
{
    logFile.close();
    // add line denoting end of log
    // flush log to file
}

/**
  * @return
  */
std::string Log::get_log()
{
    return "";
}

/**
  * @return
  */
std::string Log::get_start_time()
{
    return startTime;
}

void Log::set_start_time()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    startTime = std::string(dt);
}

/**
  * @brief
  * @param msg The message emplaced in the messageLog class attribute, also added to logFile stream
  */
void Log::emplace_back(const Message& msg)
{
    logFile << msg;
    messageLog.emplace_back(msg);
}

void Log::add_msg(Message& msg)
{
    messageLog.emplace_back(msg);
    check_for_expand();
}

void Log::add_msg(std::string& msg)
{
    messageLog.emplace_back(msg);
    check_for_expand();
}

void Log::check_for_expand()
{
    if (messageLog.size() >= messageLog.capacity()) {
        reserved += 100;
        messageLog.reserve(reserved);
    }
}

void Log::clear_log()
{
    messageLog.clear();
}
