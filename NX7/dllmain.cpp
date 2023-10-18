#include "framework.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved)
{
    if (ulReason == DLL_PROCESS_ATTACH)
    {
       // Utils::OpenDevConsole();
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, Menu::MainThread, hModule, 0, nullptr);
        Cheats::StartThread();
    }

    return TRUE;
}

