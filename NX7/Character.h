#pragma once
#include "framework.h"

namespace Character
{
	void SetCharacter()
	{
		if (Defines::Characters::Selection == "Origin")
			Utils::ChangeValue<byte>(Offsets::Player::Character, Defines::Characters::Origin);
		else if (Defines::Characters::Selection == "David")
			Utils::ChangeValue<byte>(Offsets::Player::Character, Defines::Characters::David);
		else if (Defines::Characters::Selection == "Kevin")
			Utils::ChangeValue<byte>(Offsets::Player::Character, Defines::Characters::Kevin);
		else if (Defines::Characters::Selection == "Pam")
			Utils::ChangeValue<byte>(Offsets::Player::Character, Defines::Characters::Pam);
		else if (Defines::Characters::Selection == "Cassandra")
			Utils::ChangeValue<byte>(Offsets::Player::Character, Defines::Characters::Cassandra);
		else if (Defines::Characters::Selection == "Willard")
			Utils::ChangeValue<byte>(Offsets::Player::Character, Defines::Characters::Willard);
	}
}