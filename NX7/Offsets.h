#pragma once
#include "framework.h"

namespace Offsets
{
	struct SOffset {
	public:

		SOffset(uintptr_t a, bool b)
		{
			Offset = a;
			bAddBase = b;
		}

		uintptr_t Offset = 0;
		bool bAddBase = false;
	};

	namespace Player
	{
		SOffset* Character = new SOffset(0x5ECB59D, true);
		SOffset* Money = new SOffset(0x25E4BEE4E, false);
		SOffset* Health = new SOffset(0x3D227F0, true);
		SOffset* WepAmmo1 = new SOffset(0x3CA2AC0, true);
		SOffset* WepAmmo2 = new SOffset(0x3CA2B08, true);
		SOffset* WepAmmo3 = new SOffset(0x3CA2B2C, true);
		SOffset* NoRecoil = new SOffset(0x1408E188C, false);

		SOffset* Movement = new SOffset(0x143CA6AF4, false);

		namespace Coordinates
		{
			SOffset* X = new SOffset(0x143CA2088, false);
			SOffset* Y = new SOffset(0x143CA208C, false);
			SOffset* Z = new SOffset(0x143CA2090, false);
		}
	}

	namespace Game
	{
		SOffset* Scene = new SOffset(0x6854DC0, true);
	}

	namespace Stats
	{
		SOffset* DirectorsCut = new SOffset(0x5ECB830, true);
		SOffset* XP = new SOffset(0x145ECA68C, false);
		SOffset* Kills = new SOffset(0x145ECAEC2, false);
		SOffset* HeadShots = new SOffset(0x145ECAEDE, false);
		SOffset* Downs = new SOffset(0x145ECAEBE, false);
		SOffset* HighestScene = new SOffset(0x145ECAEDA, false);
		SOffset* ScenesSurvived = new SOffset(0x145ECAED6, false);
		SOffset* PerksUsed = new SOffset(0x145ECAF0A, false);
		SOffset* DoorsOpened = new SOffset(0x145ECAEEA, false);
		SOffset* GamesPlayed = new SOffset(0x145ECAF06, false);
		SOffset* TimePlayed = new SOffset(0x145ECAF02, false);
	}

	namespace Others
	{
		SOffset* ZombieCount = new SOffset(0x143BFA168, false);
		SOffset* Timescale = new SOffset(0x146005D84, false);
	}
}