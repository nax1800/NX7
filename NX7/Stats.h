#pragma once
#include "framework.h"

namespace Stats
{
	void SetXP() 
	{ 
		Utils::ChangeValue<int>(Offsets::Stats::XP, Defines::Stats::XP); 
		LogNX("Set XP to {}", Defines::Stats::XP);
	}

	void SetKills()
	{
		Utils::ChangeValue<int>(Offsets::Stats::Kills, Defines::Stats::Kills);
		LogNX("Set Kills to {}", Defines::Stats::Kills);
	}

	void SetHeadshots()
	{
		Utils::ChangeValue<int>(Offsets::Stats::HeadShots, Defines::Stats::Headshots);
		LogNX("Set Headshots to {}", Defines::Stats::Headshots);
	}

	void SetDowns()
	{
		Utils::ChangeValue<int>(Offsets::Stats::Downs, Defines::Stats::Downs);
		LogNX("Set Downs to {}", Defines::Stats::Downs);
	}

	void SetHighestScene()
	{
		Utils::ChangeValue<int>(Offsets::Stats::HighestScene, Defines::Stats::HighestScene);
		LogNX("Set Highest Scene to {}", Defines::Stats::HighestScene);
	}

	void SetScenesSurvived()
	{
		Utils::ChangeValue<int>(Offsets::Stats::ScenesSurvived, Defines::Stats::ScenesSurvived);
		LogNX("Set Scenes Survived to {}", Defines::Stats::ScenesSurvived);
	}

	void SetPerksUsed()
	{
		Utils::ChangeValue<int>(Offsets::Stats::PerksUsed, Defines::Stats::PerksUsed);
		LogNX("Set Perks Used to {}", Defines::Stats::PerksUsed);
	}

	void SetDoorsOpened()
	{
		Utils::ChangeValue<int>(Offsets::Stats::DoorsOpened, Defines::Stats::DoorsOpened);
		LogNX("Set Doors Opened to {}", Defines::Stats::DoorsOpened);
	}

	void SetGamesPlayed()
	{
		Utils::ChangeValue<int>(Offsets::Stats::GamesPlayed, Defines::Stats::GamesPlayed);
		LogNX("Set Games Played to {}", Defines::Stats::GamesPlayed);
	}

	void SetTimePlayed()
	{
		Utils::ChangeValue<int>(Offsets::Stats::TimePlayed, Defines::Stats::TimePlayed);
		LogNX("Set Time Played to {}", Defines::Stats::TimePlayed);
	}
}