#include"log_console_output.h"
#include<iostream>
#include<string>

using namespace std;

void LogConsoleOutput::Output(const std::string& log) 
{
    cout<<log<<endl;
}