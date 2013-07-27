#pragma once
#include "UTGame.UTItemPickupFactory.h"
#include "UTGame.UTHUD.h"
#include "Engine.Pawn.h"
#include "UTGame.UTPawn.h"
#include "Engine.Controller.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTArmorPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_STRUCT(int, ShieldAmount, 976)
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.UpdateHUD");
			byte params[4] = { NULL };
			*(class UTHUD**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.SpawnCopyFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int CanUseShield(class UTPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.CanUseShield");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void AddShieldStrength(class UTPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.AddShieldStrength");
			byte params[4] = { NULL };
			*(class UTPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float BotDesireability(class Pawn* Bot, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTArmorPickupFactory.BotDesireability");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = Bot;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
#undef ADD_STRUCT
