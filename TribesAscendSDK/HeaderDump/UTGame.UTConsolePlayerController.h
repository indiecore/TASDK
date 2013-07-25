#pragma once
#include "UTGame.UTPlayerController.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTConsolePlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTConsolePlayerController : public UTPlayerController
	{
	public:
		ADD_VAR(::BoolProperty, bDebugTargetAdhesion, 0x2)
		ADD_VAR(::BoolProperty, bTargetAdhesionEnabled, 0x1)
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.UpdateRotation");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.AimingHelp");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float AimHelpModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.AimHelpModifier");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.PerformedUseAction");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClientSmartUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.ClientSmartUse");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.ClientRestart");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.PrevWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.NextWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetPlayerMovementInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.ResetPlayerMovementInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
