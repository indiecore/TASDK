#pragma once
#include "UTGame.UTItemPickupFactory.h"
#include "Engine.Pawn.h"
#include "UTGame.UTHUD.h"
#include "Engine.Controller.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTAmmoPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_OBJECT(ScriptClass, TargetWeapon, 980)
		ADD_STRUCT(int, AmmoAmount, 976)
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAmmoPickupFactory.SpawnCopyFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAmmoPickupFactory.UpdateHUD");
			byte params[4] = { NULL };
			*(class UTHUD**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float BotDesireability(class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAmmoPickupFactory.BotDesireability");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
