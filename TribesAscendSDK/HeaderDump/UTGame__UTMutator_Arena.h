#pragma once
#include "UTGame__UTMutator.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMutator_Arena." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTMutator_Arena : public UTMutator
	{
	public:
		ADD_VAR(::StrProperty, ArenaWeaponClassPath, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_Arena.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_Arena.CheckReplacement");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ModifyPlayer(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_Arena.ModifyPlayer");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
