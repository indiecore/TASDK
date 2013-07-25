#pragma once
#include "UTGame.UTCheatManager.h"
#include "Engine.Weapon.h"
namespace UnrealScript
{
	class TrCheatManager : public UTCheatManager
	{
	public:
		class Weapon* GiveWeapon(ScriptArray<wchar_t> WeaponClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCheatManager.GiveWeapon");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = WeaponClassStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Weapon**)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
