#pragma once
#include "framework.h"

namespace Player
{
	DWORD ToggleThread(LPVOID)
	{
		while (true)
		{
			if (Defines::Player::bGodMode)
				Utils::ChangeValue<int>(Offsets::Player::Health, Defines::Player::Health);

			if (Defines::Player::bInfiniteAmmo)
			{
				Utils::ChangeValue<int>(Offsets::Player::WepAmmo1, Defines::Player::Ammo);
				Utils::ChangeValue<int>(Offsets::Player::WepAmmo2, Defines::Player::Ammo);
				Utils::ChangeValue<int>(Offsets::Player::WepAmmo3, Defines::Player::Ammo);
			}

			if (Defines::Player::bNoRecoil)
				Utils::ChangeValue<int>(Offsets::Player::NoRecoil, 11437327);
			else
				Utils::ChangeValue<int>(Offsets::Player::NoRecoil, 11437071);
		}
	}

	void SetMoney()
	{
		Utils::ChangeValue<int>(Offsets::Player::Money, Defines::Player::AmountPoints);
		LogNX("Set Money to {}", Defines::Player::AmountPoints);
	}

	void ToggleNoClip()
	{
		byte Movement = Utils::ReadValue<byte>(Offsets::Player::Movement);
		if (Movement == 0)
		{
			Utils::ChangeValue<byte>(Offsets::Player::Movement, 2);
			Defines::Player::bNoClip = true;
		}
		else
		{
			Utils::ChangeValue<byte>(Offsets::Player::Movement, 0);
			Defines::Player::bNoClip = false;
		}
	}

	void SetCoordinates()
	{
		Utils::ChangeValue<float>(Offsets::Player::Coordinates::X, Defines::Player::Coordinates::X);
		Utils::ChangeValue<float>(Offsets::Player::Coordinates::Y, Defines::Player::Coordinates::Y);
		Utils::ChangeValue<float>(Offsets::Player::Coordinates::Z, Defines::Player::Coordinates::Z);
		LogNX("Set Coordinates to: X:{}, Y:{}, Z:{}", Defines::Player::Coordinates::X, Defines::Player::Coordinates::Y, Defines::Player::Coordinates::Z);
	}
}