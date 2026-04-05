#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    if (!fs::exists("Data")) {
        fs::create_directory("Data");
    }

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char cmd[] = "dotnet DofusMage.UI.dll";

    if (CreateProcessA(
            NULL,
            cmd,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi)) 
    {
        std::cout << "[+] Launched successfully." << std::endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } 
    else {
        std::cout << "[-] Failed to launch. Error: " << GetLastError() << std::endl;
    }

    return 0;
}