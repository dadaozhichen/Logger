#pragma once
#include"log_format.h"

class XmlLogFormat:public LogFormat
{
public:
// 日志级别
    std::string Format(const std::string &level,
                        const std::string &log,
                        const std::string &file,
                        int line
                    );
};
