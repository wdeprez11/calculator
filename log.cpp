#include "log.h"

Message::Message()
    : message(" ")
{
}

Message::Message(std::string& newMessage)
    : message(newMessage)
{
}

Message::Message(Message& newMessage)
    : message(newMessage.message)
{
}

Log::Log()
    : msgLog()
{
    msgLog.reserve(10);
}

Log::Log(const Log& oldLog)
    : msgLog(oldLog.msgLog)
    , prevMsg(oldLog.prevMsg)
{
    msgLog.reserve(10);
}

Log::~Log()
{
    // add line
    // flush log to file
}

std::string Log::GetPrevMsg() const
{
    return prevMsg;
}

std::string Log::GetLog() const
{
    return "";
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
