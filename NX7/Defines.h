#pragma once
#include "framework.h"

namespace Defines
{
	namespace Menu
	{
		bool bShow = true;
	}

	namespace Game
	{
		int Scene = 1;
		float Timescale = 1.0f;
		int DirectorsCut = 8325057;
	}

	namespace Characters
	{
		const char* List[] = { "Origin", "David", "Kevin", "Pam", "Cassandra", "Willard" };
		static const char* Selection = "Origin";

		byte Origin = 0;
		byte David = 1;
		byte Kevin = 2;
		byte Pam = 3;
		byte Cassandra = 4;
		byte Willard = 5;
	}

	namespace Player
	{
		int Ammo = 1000;
		int Health = 1000;
		int AmountPoints = 1000000;

		bool bInfiniteMoney = false;
		bool bInfiniteAmmo = false;
		bool bGodMode = false;
		bool bNoRecoil = false;
		bool bNoClip = false;

		namespace Coordinates
		{
			float X = 467.546f;
			float Y = 3677.474f;
			float Z = 0.068f;
		}
	}

	namespace Stats
	{
		int XP = 95310685;
		int Kills = 0;
		int Headshots = 0;
		int Downs = 0;
		int HighestScene = 0;
		int ScenesSurvived = 0;
		int PerksUsed = 0;
		int DoorsOpened = 0;
		int GamesPlayed = 0;
		int TimePlayed = 0;

		bool IsDirectorsCut()
		{
			int DC = Utils::ReadValue<int>(Offsets::Stats::DirectorsCut);
			if (DC == Defines::Game::DirectorsCut || DC == (Defines::Game::DirectorsCut - 1))
				return true;

			return false;
		}
	}
}