#include "include/HopeDucky.h"

using namespace std;

int main(){

    GUIR();
    
    Sleep(500);
    PressKeys("powershell");
    Sleep(500);
    ReturnKey();
    Sleep(500);
    PressKeys("echo 'HopeDucky Say Hello.'");
    Sleep(500);
    ReturnKey();
    

    return 0x0;
}
