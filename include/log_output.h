#pragma once 
#include<string>


class LogOutput
{
public:
    virtual void Output(const std::string& log)=0;
};