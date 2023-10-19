#pragma once
#include "framework.h"
#include <sstream>

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace Menu
{
	Present oPresent;
	HWND window = NULL;
	WNDPROC oWndProc;
	ID3D11Device* pDevice = NULL;
	ID3D11DeviceContext* pContext = NULL;
	ID3D11RenderTargetView* mainRenderTargetView;

	void InitImGui()
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
		ImGui_ImplWin32_Init(window);
		ImGui_ImplDX11_Init(pDevice, pContext);
	}

	LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

		if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
			return true;

		return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
	}

	static void Watermark(bool p_open = true)
	{
		const float DISTANCE = 15.0f;
		static int corner = 0;
		ImGuiIO& io = ImGui::GetIO();
		if (corner != -1)
		{
			ImVec2 window_pos = ImVec2((corner & 1) ? io.DisplaySize.x - DISTANCE : DISTANCE, (corner & 2) ? io.DisplaySize.y - DISTANCE : DISTANCE);
			ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
			ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		}
		ImGui::SetNextWindowBgAlpha(0.65f); // Transparent background
		if (ImGui::Begin("Watermarkss", &p_open, (corner != -1 ? ImGuiWindowFlags_NoMove : 0) | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
		{
			ImGui::Text("NX7 || discord.gg/QnypahWX8V");
			ImGui::Separator();
			ImGui::Text("Toggle Menu: F4/Ins");
			ImGui::Separator();
			ImGui::Text("Zombie Count: %i", Utils::ReadValue<int>(Offsets::Others::ZombieCount));
			if (ImGui::BeginPopupContextWindow())
			{
				if (ImGui::MenuItem("Custom", NULL, corner == -1)) corner = -1;
				if (ImGui::MenuItem("Top-left", NULL, corner == 0)) corner = 0;
				if (ImGui::MenuItem("Top-right", NULL, corner == 1)) corner = 1;
				if (ImGui::MenuItem("Bottom-left", NULL, corner == 2)) corner = 2;
				if (ImGui::MenuItem("Bottom-right", NULL, corner == 3)) corner = 3;
			}
		}
		ImGui::End();
	}

	bool init = false;
	HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
	{
		if (!init)
		{
			if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
			{
				pDevice->GetImmediateContext(&pContext);
				DXGI_SWAP_CHAIN_DESC sd;
				pSwapChain->GetDesc(&sd);
				window = sd.OutputWindow;
				ID3D11Texture2D* pBackBuffer;
				pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
				pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
				pBackBuffer->Release();
				oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
				InitImGui();
				init = true;
			}

			else
				return oPresent(pSwapChain, SyncInterval, Flags);
		}

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		Styles::Comfy();


		if (GetAsyncKeyState(VK_F4) & 1 || GetAsyncKeyState(VK_INSERT) & 1)
			Defines::Menu::bShow = !Defines::Menu::bShow;

		Watermark();

		if (Defines::Menu::bShow)
		{
			ImGui::Begin("NX7 || Zombies");
			ImGui::SetWindowSize("NX7 || Zombies", { 635.f, 375.f });
			ImGui::BeginTabBar("TabBar");
			if (ImGui::BeginTabItem("Main"))
			{
				ImGui::Text("Menu made by @nax1800.");
				ImGui::Text("Join the discord for future updates ;)");
				if (ImGui::Button("Join Discord"))
				{
					Utils::StartCMD("https://discord.gg/QnypahWX8V");
				}
				ImGui::Separator();		
				if (ImGui::Button("Toggle"))
					Stats::ToggleDirectorsCut();
				ImGui::SameLine();
				ImGui::Text("Director's Cut Unlocked: %s", Defines::Stats::IsDirectorsCut() ? "True" : "False");
				ImGui::Text("Current Character: %s", Defines::Characters::Selection);
				if (ImGui::BeginCombo("Character", Defines::Characters::Selection))
				{
					for (int n = 0; n < IM_ARRAYSIZE(Defines::Characters::List); n++)
					{
						bool is_selected = (Defines::Characters::Selection == Defines::Characters::List[n]);
						if (ImGui::Selectable(Defines::Characters::List[n], is_selected))
							Defines::Characters::Selection = Defines::Characters::List[n];
							if (is_selected)
								ImGui::SetItemDefaultFocus();
					}
					ImGui::EndCombo();
				}
				ImGui::SameLine();
				if (ImGui::Button("Select"))
					Character::SetCharacter();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Game"))
			{
				ImGui::SliderFloat("Timescale", &Defines::Game::Timescale, 1.0f, 10.0f, "%.0f");
				ImGui::SameLine();
				if (ImGui::Button("Set Timescale"))
					Game::SetTimescale();
				ImGui::InputInt("Scene", &Defines::Game::Scene);
				ImGui::SameLine();
				if (ImGui::Button("Set Scene"))
					Game::SetScene();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Player"))
			{
				ImGui::Checkbox("God Mode", &Defines::Player::bGodMode);
				ImGui::SameLine();
				ImGui::Checkbox("Infinite Ammo", &Defines::Player::bInfiniteAmmo);
				ImGui::SameLine();
				ImGui::Checkbox("No Recoil", &Defines::Player::bNoRecoil);
				if (ImGui::Button("Toggle"))
					Player::ToggleNoClip();
				ImGui::SameLine();
				ImGui::Text("No Clip: %s", Defines::Player::bNoClip ? "True" : "False");
				ImGui::Separator();
				ImGui::InputInt("Money", &Defines::Player::AmountPoints, 1, 1000000);
				ImGui::SameLine();
				if(ImGui::Button("Set"))
					Player::SetMoney();
				ImGui::Separator();
				ImGui::Text("Coordinates");
				ImGui::Separator();
				ImGui::Text("Current Coords: X: %.3f, Y: %.3f, Z: %.3f", Utils::ReadValue<float>(Offsets::Player::Coordinates::X), Utils::ReadValue<float>(Offsets::Player::Coordinates::Y), Utils::ReadValue<float>(Offsets::Player::Coordinates::Z));
				ImGui::Separator();
				ImGui::Text("Warning: You may teleport outside the map (you will probably die),\nif you do not know the percise Coords.");
				ImGui::InputFloat("X", &Defines::Player::Coordinates::X, 1);
				ImGui::InputFloat("Y", &Defines::Player::Coordinates::Y, 1);
				ImGui::InputFloat("Z", &Defines::Player::Coordinates::Z, 1);
				if (ImGui::Button("Teleport"))
					Player::SetCoordinates();

				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Stats"))
			{
				ImGui::Text("Max XP (Level 999) = 95310685.");
				ImGui::Separator();
				ImGui::InputInt("XP", &Defines::Stats::XP);
				ImGui::SameLine();
				if (ImGui::Button("Min"))
					Defines::Stats::XP = 0;
				ImGui::SameLine();
				if (ImGui::Button("Max"))
					Defines::Stats::XP = 95310685;
				ImGui::SameLine();
				if (ImGui::Button("Set XP"))
					Stats::SetXP();
				ImGui::InputInt("Kills", &Defines::Stats::Kills);
				ImGui::SameLine();
				if (ImGui::Button("Set Kills"))
					Stats::SetKills();
				ImGui::InputInt("Headshots", &Defines::Stats::Headshots);
				ImGui::SameLine();
				if (ImGui::Button("Set Headshots"))
					Stats::SetHeadshots();
				ImGui::InputInt("Downs", &Defines::Stats::Downs);
				ImGui::SameLine();
				if (ImGui::Button("Set Downs"))
					Stats::SetDowns();
				ImGui::InputInt("Highest Scene", &Defines::Stats::HighestScene);
				ImGui::SameLine();
				if (ImGui::Button("Set HS"))
					Stats::SetHighestScene();
				ImGui::InputInt("Scenes Survived", &Defines::Stats::ScenesSurvived);
				ImGui::SameLine();
				if (ImGui::Button("Set SS"))
					Stats::SetScenesSurvived();
				ImGui::InputInt("Perks Used", &Defines::Stats::PerksUsed);
				ImGui::SameLine();
				if (ImGui::Button("Set Perks Used"))
					Stats::SetPerksUsed();
				ImGui::InputInt("Doors Opened", &Defines::Stats::DoorsOpened);
				ImGui::SameLine();
				if (ImGui::Button("Set Doors Opened"))
					Stats::SetDoorsOpened();
				ImGui::InputInt("Games Played", &Defines::Stats::GamesPlayed);
				ImGui::SameLine();
				if (ImGui::Button("Set Games Played"))
					Stats::SetGamesPlayed();
				ImGui::InputInt("Time Played", &Defines::Stats::TimePlayed);
				ImGui::SameLine();
				if (ImGui::Button("Set Time Played"))
					Stats::SetTimePlayed();
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
			ImGui::End();
		}

		ImGui::Render();

		pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		return oPresent(pSwapChain, SyncInterval, Flags);
	}

	DWORD WINAPI MainThread(LPVOID lpReserved)
	{
		bool init_hook = false;
		do
		{
			if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
			{
				kiero::bind(8, (void**)&oPresent, hkPresent);
				init_hook = true;
			}
		} while (!init_hook);
		return TRUE;
	}
}