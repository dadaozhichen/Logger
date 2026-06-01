#pragma once
#include<string>

class LogFormat{
public:
// 日志级别
    virtual std::string Format(const std::string &level,
                        const std::string &log,
                        const std::string &file,
                        int line
                    )=0;
};
