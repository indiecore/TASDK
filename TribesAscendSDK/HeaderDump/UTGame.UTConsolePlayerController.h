#pragma once
#include "UTGame.UTPlayerController.h"
#include "Engine.Pawn.h"
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
	class UTConsolePlayerController : public UTPlayerController
	{
	public:
		class ProfileSettingToUE3BindingDatum
		{
		public:
			ADD_STRUCT(ScriptName, UE3BindingName, 8)
			ADD_STRUCT(ScriptName, ProfileSettingName, 0)
		};
		ADD_STRUCT(ScriptArray<UTConsolePlayerController::ProfileSettingToUE3BindingDatum>, ProfileSettingToUE3BindingMapping360, 2180)
		ADD_STRUCT(ScriptArray<UTConsolePlayerController::ProfileSettingToUE3BindingDatum>, ProfileSettingToUE3BindingMappingPS3, 2192)
		ADD_BOOL(bDebugTargetAdhesion, 2176, 0x2)
		ADD_BOOL(bTargetAdhesionEnabled, 2176, 0x1)
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.UpdateRotation");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.AimingHelp");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float AimHelpModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.AimHelpModifier");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.PerformedUseAction");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClientSmartUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.ClientSmartUse");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerController.ClientRestart");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
#undef ADD_BOOL
#undef ADD_STRUCT
