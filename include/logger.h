#include<iostream>
#include"log_output.h"
#include"log_format.h"
#include<string>
enum class XLog
{
    DEBUG,
    INFO,
    ERROR,
    FATAL
};

class Logger
{
public:
    Logger();
    ~Logger();
    void Write(XLog level,
                        const std::string &log,
                        const std::string &file,
                        int line);
    void SetOutput(LogOutput* out);
    void SetFormater(LogFormat* formater);
    void SetLevel(XLog level);
private:
    LogOutput* output_{nullptr};
    LogFormat* formater_{nullptr};
    XLog log_level_{XLog::DEBUG};
};