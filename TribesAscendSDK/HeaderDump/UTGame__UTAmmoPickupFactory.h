#pragma once
#include "UTGame__UTItemPickupFactory.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "UTGame__UTHUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTAmmoPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTAmmoPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTAmmoPickupFactory : public UTItemPickupFactory
	{
	public:
		ADD_OBJECT(ScriptClass, TargetWeapon)
		ADD_VAR(::IntProperty, AmmoAmount, 0xFFFFFFFF)
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAmmoPickupFactory.SpawnCopyFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAmmoPickupFactory.UpdateHUD");
			byte* params = (byte*)malloc(4);
			*(class UTHUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float BotDesireability(class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAmmoPickupFactory.BotDesireability");
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
#undef ADD_OBJECT
