#pragma once
#include "framework.h"

namespace Game
{
	void SetTimescale()
	{
		Utils::ChangeValue<float>(Offsets::Others::Timescale, Defines::Game::Timescale);
		LogNX("Set Timescale to {}", Defines::Game::Timescale);
	}

	void SetScene()
	{
		Utils::ChangeValue<int>(Offsets::Game::Scene, Defines::Game::Scene);
		LogNX("Set Scene to {}", Defines::Game::Scene);
	}
}