#pragma once
#include<string>
#include"logger.h"
class LogFac{
public:
    static LogFac& Instance()
    {
        static LogFac fac;
        return fac;
    }
    void Init(const std::string& con_file="log.conf");
    Logger& logger(){return logger_;}
private:
    LogFac(){};
    Logger logger_;
};

#define XLOGOUT(l,s) LogFac::Instance().logger().Write(l,s,__FILE__,__LINE__) 
#define LOGDEBUG(s) XLOGOUT(XLog::DEBUG,s)
#define LOGINFO(s) XLOGOUT(XLog::INFO,s)
#define LOGERROR(s) XLOGOUT(XLog::ERROR,s)
#define LOGFATRAL(s) XLOGOUT(XLog::FATAL,s)