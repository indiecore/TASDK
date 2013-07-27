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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40619);
			byte params[4] = { NULL };
			*(class UTHUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40622);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40623);
			byte params[4] = { NULL };
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int CanUseShield(class UTPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40627);
			byte params[8] = { NULL };
			*(class UTPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void AddShieldStrength(class UTPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40630);
			byte params[4] = { NULL };
			*(class UTPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float BotDesireability(class Pawn* Bot, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40644);
			byte params[12] = { NULL };
			*(class Pawn**)params = Bot;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
#undef ADD_STRUCT
