#include"log_output.h"
#include<iostream>

class LogConsoleOutput:public LogOutput
{
public:
    void Output(const std::string& log) override;
};