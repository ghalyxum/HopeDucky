# HopeDucky
Rubber Ducky As C++ Programme

## Install

````

git clone https://github.com/ghalypr/HopeDucky.git

````



## Usage


````C++

#include "include/HopeDucky.h"

using namespace std;

int main(){

    GUIR();
    
    Sleep(500);
    PressKeys("powershell");
    Sleep(500);
    ReturnKey();
    Sleep(500);
    PressKeys("echo 'Hello World From HopeDucky!'");
    Sleep(500);
    ReturnKey();
    

    return 0x0;
}



````
