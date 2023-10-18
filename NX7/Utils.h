#pragma once
#include "framework.h"

namespace Utils
{
	void OpenDevConsole()
	{
		AllocConsole();
		FILE* File;
		freopen_s(&File, "CONOUT$", "w", stdout);
		SetConsoleTitleA("NX7 || DEV CONSOLE");
	}

	void StartCMD(std::string Link)
	{
		std::string CMD = "start " + Link;
		system(CMD.c_str());
	}

	uintptr_t Offset(uintptr_t A) 
	{ 
		return (uintptr_t)GetModuleHandleA(0) + A; 
	}

	template<typename T>
	T* Pointer(Offsets::SOffset* SOffset) 
	{ 
		uintptr_t Addr = 0;

		if (SOffset->bAddBase)
			Addr = Offset(SOffset->Offset);
		else
			Addr = SOffset->Offset;

		return (T*)Addr; 
	}

	template<typename T>
	void ChangeValue(Offsets::SOffset* Offset, T NewValue)
	{
		T* _Pointer = Pointer<T>(Offset);

		if(*_Pointer != NewValue)
			*_Pointer = NewValue;
	}

	template<typename T>
	T ReadValue(Offsets::SOffset* Offset)
	{
		T* _Pointer = Pointer<T>(Offset);
		return *_Pointer;
	}
}