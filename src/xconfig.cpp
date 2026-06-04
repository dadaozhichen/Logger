#include"xconfig.h"
#include<fstream>
#include<iostream>
using namespace std;
bool XConfig::Read(const string& file){
    ifstream in(file);
    cout<<in.is_open()<<__FILE__<<__LINE__<<endl;
    if(!in.is_open()) return false;
    string line;
    
    while(getline(in,line)){
        if(!line.empty()){
            auto p = line.find('=');
            if(p<=0) continue;
            string k = line.substr(0,p);
            string v = line.substr(p+1);
            conf_[k]=v;
        }
        else break;
    }
    return true;
    
}
const string& XConfig::Get(const string& key){
    auto c = conf_.find(key);
    if(c==conf_.end()) return "";
    else return c->second;
}


