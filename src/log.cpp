#include "log.h"
#include <ctime>
#include <fstream>

Message::Message(int type, std::string msg)
    : msgType(type)
    , message(msg)
{
}

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

std::string Message::get_message()
{
    return message;
}

std::ofstream& Message::operator<<(std::ofstream stream, const Message& other)
{
    stream << other.message << '\n';
    //return stream;
}

Log::Log()
    : reserved(100)
    , logFile("log.txt")
{
    set_start_time();
    //logFile.open(("log" + startTime).c_str());
    emplace_back(Message(0, "Initializing Log..."));
    emplace_back(Message(0, "Log started at: " + std::string(startTime.c_str())));
    emplace_back(Message(0, "Waiting for user input..."));
}

Log::Log(const Log& oldLog)
    : startTime(oldLog.startTime)
{
}

Log::~Log()
{
    logFile.close();
    // add line denoting end of log
    // flush log to file
}

std::string Log::get_log()
{
    return "";
}

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
