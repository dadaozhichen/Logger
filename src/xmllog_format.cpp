#include"xmllog_format.h"
#include<string>
#include<sstream>
using namespace std;
string XmlLogFormat::Format(const std::string &level,
                        const std::string &log,
                        const std::string &file,
                        int line
                    )
{
    stringstream ss;

    ss<<"level: "<<level<<"\n"
        <<"log: "<<log<<"\n"
        <<"file: "<<__FILE__<<"\n"
        <<"line: "<<__LINE__<<"\n";
    
    
    return ss.str();
}