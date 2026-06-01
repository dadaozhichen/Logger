#include"log_fac.h"
#include"log_console_output.h"
#include"log_file_output.h"
#include"xlog_format.h"


void LogFac::Init(const std::string& con_file)
{
    logger_.SetFormater(new XLogFormat);
    logger_.SetOutput(new LogConsoleOutput);
}