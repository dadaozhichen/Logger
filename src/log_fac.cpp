#include"log_fac.h"
#include"log_console_output.h"
#include"log_file_output.h"
#include"xlog_format.h"
#include"xmllog_format.h"
#include"xconfig.h"
#include<iostream>
#define LOGFILE "log.txt"
using namespace std;
void LogFac::Init(const std::string& con_file)
{
    
    XConfig conf;
    bool re = conf.Read(con_file);
    
    std::string log_type = "console";
    std::string log_file = LOGFILE;
    std::string log_level = "debug";
    std::string log_format = "xml";
    if(re)
    {
        log_file = conf.Get("log_file");
        log_type = conf.Get("log_type");
        log_level = conf.Get("log_level");
        log_format = conf.Get("log_format");
    }
    if(log_format=="xml")
        logger_.SetFormater(make_unique<XmlLogFormat>());
    else if(log_format=="x")
        logger_.SetFormater(make_unique<XLogFormat>());
    if(log_type=="file")
    {
        if(log_file.empty()) log_file=LOGFILE;
        auto fout = make_unique<LogFileOutput>();
        if(fout->Open(log_file))
        {
            std::cerr<<"failed"<<std::endl;
        }
        logger_.SetOutput(move(fout));
        if(log_level=="debug")
        {
            logger_.SetLevel(XLog::DEBUG);
        }
        else if(log_level=="info")
        {
            logger_.SetLevel(XLog::INFO);
        }
        else if(log_level=="error")
        {
            logger_.SetLevel(XLog::ERROR);
        }
        else 
        {
            logger_.SetLevel(XLog::FATAL);
        }
    }
    else{
        logger_.SetOutput(make_unique<LogConsoleOutput>());
    }
}