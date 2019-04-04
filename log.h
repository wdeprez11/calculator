#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <vector>

class Message {
private:
    int msgType;
    std::string message;

public:
    Message(int type, std::string msg);
    std::string get_error_type();
    std::string get_message();
    std::ofstream& operator<<(std::ofstream& stream, const Message& other);
    //std::ofstream& operator>>(std::ifstream& stream, Message& other);
};

class Log {
private:
    std::vector<Message> messageLog;
    std::string startTime;
    std::ifstream logFile;
    int reserved;
    void check_for_expand();
    void set_start_time();

public:
    Log();
    Log(const Log& old);
    ~Log();
    std::string get_line(int i);
    std::string get_line(std::string error);
    std::string get_log();
    std::string get_start_time();
    void emplace_back(const Message message);
    void set_log(Log& newLog);
    void add_msg(std::string& msg);
    void add_msg(Message& msg);
    void clear_log();
};

#endif // LOG_H
