#include "include/keys.h"




void PressKeys_Pure(const std::wstring &str)
{
    int len = str.length();
    if (len == 0) return;

    std::vector<INPUT> in(len*2);
    ZeroMemory(&in[0], in.size()*sizeof(INPUT));

    int i = 0, idx = 0;
    while (i < len)
    {
        WORD ch = (WORD) str[i++];

        if ((ch < 0xD800) || (ch > 0xDFFF))
        {
            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = ch;
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx] = in[idx-1];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
        else
        {
            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = ch;
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = (WORD) str[i++];
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx] = in[idx-2];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;

            in[idx] = in[idx-2];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
    }

    SendInput(in.size(), &in[0], sizeof(INPUT));
}

void PressKeys(string str){
    PressKeys_Pure(String2WString(str));
}

void WinKey(){

        INPUT ip;
        // Set up a generic keyboard event.
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0; // hardware scan code for key
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;

        // Press the key
        ip.ki.wVk = VK_LWIN; // virtual-key code for the key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        // Release the key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));
}


void GUIR(){

        INPUT ip;
        // Set up a generic keyboard event.
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0; // hardware scan code for key
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;

        // Left LWIN key
        ip.ki.wVk = VK_LWIN; // virtual-key code for the key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));
        

        // seconed
        ip.ki.wVk = 0x52;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));

        // Release the <<R>> key
        ip.ki.wVk = 0x52;
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));

        // Release the <<LWIN>> key
        ip.ki.wVk = VK_LWIN;
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));
}


void ReturnKey(){

        INPUT ip;
        // Set up a generic keyboard event.
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0; // hardware scan code for key
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;

        // Press the key
        ip.ki.wVk = VK_RETURN; // virtual-key code for the key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        // Release the key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));
}


