#pragma once
#include "UTGame.UTItemPickupFactory.h"
#include "UTGame.UTHUD.h"
#include "Engine.Pawn.h"
#include "Engine.Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTHealthPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTHealthPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_VAR(::BoolProperty, bSuperHeal, 0x1)
		ADD_VAR(::IntProperty, HealingAmount, 0xFFFFFFFF)
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHealthPickupFactory.UpdateHUD");
			byte* params = (byte*)malloc(4);
			*(class UTHUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHealthPickupFactory.SpawnCopyFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int HealAmount(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHealthPickupFactory.HealAmount");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		float BotDesireability(class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHealthPickupFactory.BotDesireability");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
