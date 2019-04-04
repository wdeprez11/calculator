#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <vector>

class Message {
private:
    std::string message;

public:
    Message();
    Message(std::string& msg);
    Message(Message& msg);
    std::string GetMessage() const;
    void SetMessage(std::string& msg);
    void SetMessage(Message& msg);
};

class Log {
private:
    std::vector<Message> msgLog;
    std::string prevMsg;

public:
    Log();
    Log(const Log& old);
    ~Log();
    std::string GetPrevMsg() const;
    std::string GetLog() const;
    void DeletePrevMsg();
    void SetLog(Log& newLog);
    void AddMsg(std::string& msg);
    void AddMsg(Message& msg);
    void ClearLog();
};

#endif // LOG_H
