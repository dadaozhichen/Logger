#include"log_fac.h"
#include<iostream>
int main()
{
    LogFac::Instance().Init();
    LogFac::Instance().logger().Write(XLog::DEBUG,"test",__FILE__,__LINE__);
    LOGDEBUG("test LogFac debug");

    return 0;
}