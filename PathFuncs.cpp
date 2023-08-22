#include "include/PathFuncs.h"


using namespace std;


string FullPath(){
    char re[MAX_PATH];
    return string(re,GetModuleFileName(NULL,re,MAX_PATH));
}

string CurrentPath(){

    return FullPath().substr(0,FullPath().find_last_of("\\"));
}

    
char * User(){

     return getenv("username");
}    


string StartUpPath(){

    return "C:\\Users\\" + string(User()) + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";
}

    
string CarryPath(){

    return "C:\\Users\\" + string(User()) + "\\hope"; 

}    
     
    
string StyleTwoPaths(string p1,string p2){

    char StyleSign = '"';
    std::string SS(1, StyleSign);
    return (SS+p1+SS)+" "+(SS+p2+SS);
    
}
