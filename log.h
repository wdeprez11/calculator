#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <vector>

class Message {
private:
    std::string message;

public:
    Message();
    Message(const std::string& msg);
    Message(const Message& msg);
    std::string GetMessage() const;
    void SetMessage(std::string& msg);
    void SetMessage(Message& msg);
};

class Log {
private:
    std::vector<Message> msgLog;
    std::string prevMsg;
    std::string startTime;

public:
    Log();
    Log(const Log& old);
    ~Log();
    std::string GetPrevMsg() const;
    std::string GetLog() const;
    std::string GetStartTime() const;
    void FlushLog();
    void DeletePrevMsg();
    void SetLog(Log& newLog);
    void AddMsg(std::string& msg);
    void AddMsg(Message& msg);
    void ClearLog();
    std::ofstream& operator<<(std::ofstream& stream, const Message& other);
};

#endif // LOG_H
