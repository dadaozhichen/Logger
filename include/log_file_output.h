#include"log_output.h"
#include<fstream>
#include<iostream>

class LogFileOutput:public LogOutput
{
public:
    bool Open(const std::string& filename);
    void Output(const std::string& log) override;
private:
    std::ofstream out_;
};