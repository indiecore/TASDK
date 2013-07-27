#pragma once
#include "UTGame.UTCheatManager.h"
#include "Engine.Weapon.h"
namespace UnrealScript
{
	class TrCheatManager : public UTCheatManager
	{
	public:
		class Weapon* GiveWeapon(ScriptString* WeaponClassStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74480);
			byte params[16] = { NULL };
			*(ScriptString**)params = WeaponClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Weapon**)&params[12];
		}
	};
}
