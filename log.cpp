#include "log.h"
#include <ctime>
#include <fstream>

Message::Message()
    : message("")
{
}

Message::Message(const std::string& newMessage)
    : message(newMessage)
{
}

Message::Message(const Message& newMessage)
    : message(newMessage.message)
{
}

Log::Log()
    : msgLog()
    , startTime(ctime(time(0)))
{
    time_t now = time(0);
    char* dt = ctime(&now);
    startTime = std::string(dt);
    msgLog.reserve(100);
    msgLog.emplace_back(Message("Initializing Log"));
    msgLog.emplace_back(Message("Log Started at: " + startTime /*time*/));
    msgLog.emplace_back(Message("Waiting for user..."));
}

Log::Log(const Log& oldLog)
    : msgLog(oldLog.msgLog)
    , prevMsg(oldLog.prevMsg)
    , startTime(oldLog.startTime)
{
}

Log::~Log()
{
    // add line denoting end of log
    // flush log to file
}

void Log::FlushLog()
{
    std::ofstream logFile;
    logFile.open("log" + startTime);
    for (long unsigned int i = 0; i < msgLog.size(); ++i) {
        logFile << msgLog[i];
    }
    // want to call this automatically each time vector reaches capacity (every 100 lines)
    // write msgLog vector to file
    // clear msgLog
    ClearLog();
}

std::string Log::GetPrevMsg() const
{
    return prevMsg;
}

std::string Log::GetLog() const
{
    return "";
}

std::string Log::GetStartTime() const
{
    return startTime;
}

void Log::DeletePrevMsg()
{
}

void Log::AddMsg(Message& msg)
{
    msgLog.emplace_back(msg);
}

void Log::AddMsg(std::string& msg)
{
    msgLog.emplace_back(msg);
}

void Log::ClearLog()
{
    msgLog.clear();
}

std::ofstream& operator<<(std::ofstream stream, const Message& other)
{
    stream << other.message << '\n';
    return stream;
}
