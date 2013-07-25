#pragma once
#include "UTGame.UTItemPickupFactory.h"
#include "UTGame.UTHUD.h"
#include "Engine.Pawn.h"
#include "UTGame.UTPawn.h"
#include "Engine.Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTArmorPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTArmorPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_VAR(::IntProperty, ShieldAmount, 0xFFFFFFFF)
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.UpdateHUD");
			byte* params = (byte*)malloc(4);
			*(class UTHUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.SpawnCopyFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int CanUseShield(class UTPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.CanUseShield");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddShieldStrength(class UTPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.AddShieldStrength");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float BotDesireability(class Pawn* Bot, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.BotDesireability");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Bot;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
