#pragma once
#include "UTGame.UTItemPickupFactory.h"
#include "UTGame.UTHUD.h"
#include "Engine.Pawn.h"
#include "Engine.Controller.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTHealthPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_BOOL(bSuperHeal, 980, 0x1)
		ADD_STRUCT(int, HealingAmount, 976)
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47961);
			byte params[4] = { NULL };
			*(class UTHUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47963);
			byte params[4] = { NULL };
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int HealAmount(class Pawn* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47965);
			byte params[8] = { NULL };
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float BotDesireability(class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47978);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
