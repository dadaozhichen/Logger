#include<iostream>
#include<string>
#include"logger.h"


Logger::Logger()
{
    std::cout<<"Create Logger"<<std::endl;
}
Logger::~Logger()
{
    std::cout<<"delete output_"<<std::endl;
    //delete output_;
    //output_=nullptr;
    std::cout<<"delete formater_"<<std::endl;
    //delete formater_;
    //formater_ = nullptr;
    std::cout<<"Drop Logger"<<std::endl;
}

void Logger::Write(XLog level,
                        const std::string &log,
                        const std::string &file,
                        int line){

    if(level<log_level_) return ;

    std::string levelstr{"debug"};    
    switch (level)
    {
    case XLog::DEBUG:
        break;
    case XLog::INFO:
        levelstr = "info";
        break;
    case XLog::ERROR:
        levelstr = "error";
        break;
    case XLog::FATAL:
        levelstr = "fatal";
        break;
    default:
        break;
    }
    
    auto str = formater_->Format(levelstr,log,file,line);
    output_->Output(str);
}

void Logger::SetOutput(std::unique_ptr<LogOutput> out){
    output_=move(out);
}
void Logger::SetFormater(std::unique_ptr<LogFormat> formater){
    formater_ = move(formater);
}
void Logger::SetLevel(XLog level){
    log_level_=level;
}