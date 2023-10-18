#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <d3d11.h>
#include <dxgi.h>
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "Memcury.h"

#define LogNX(...) { std::cout << "[NX7]: " << std::format(__VA_ARGS__) << std::endl; }

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

#include "Offsets.h"
#include "Utils.h"
#include "Defines.h"
#include "Cheats.h"
#include "Stats.h"
#include "Style.h"
#include "Menu.h"
