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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCheatManager.GiveWeapon");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = WeaponClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Weapon**)&params[12];
		}
	};
}
