#include "xlog_format.h"
#include<sstream>
using namespace std;

string XLogFormat::Format(const string &level,
                        const string &log,
                        const string &file,
                        int line
)
{
    stringstream ss;
    
    ss<<level<<" "<<log<<" "<<file<<":"<<line;

    return ss.str();
}