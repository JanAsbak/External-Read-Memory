#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <chrono>
#include <thread>

using namespace std;



int main()
{
    
    int Pid = 0;

    cout << "Pid: "; // Input ProcessId of Your targeted process
    cin >> Pid; 
    cout << endl;

    HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, false, Pid);

    uintptr_t MemoryAddress = 0; //Your Offset Address
    int MemoryData = 0;

    while (true)
    {
        BOOL ReadAmmo = ReadProcessMemory(ProcessHandle, (LPCVOID)MemoryAddress, &MemoryData, sizeof(int), false); //Read the address and save decimal into int MemoryData.
        if (!ReadAmmo)
        {
            cout << "Cant Read Process Memory" << endl;
        }

        cout << MemoryData << endl;
    }


    return 0;
}
