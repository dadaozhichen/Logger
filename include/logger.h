#pragma once 
#include<iostream>
#include"log_output.h"
#include"log_format.h"
#include<string>
#include<memory>
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
    void SetOutput(std::unique_ptr<LogOutput> out);
    void SetFormater(std::unique_ptr<LogFormat> formater);
    void SetLevel(XLog level);
private:
    // LogOutput* output_{nullptr};
    // LogFormat* formater_{nullptr};
    std::unique_ptr<LogOutput> output_;
    std::unique_ptr<LogFormat> formater_;
    XLog log_level_{XLog::DEBUG};
};