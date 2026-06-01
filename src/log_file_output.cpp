#include"log_file_output.h"
#include<fstream>
#include<iostream>

bool LogFileOutput::Open(const std::string& filename){
    out_.open(filename,std::ios::app);
    if(!out_.is_open()) return false;
    else return true;
}
void LogFileOutput::Output(const std::string& log) {
    out_<<log<<std::endl;
}
