#pragma once
#include "Engine.Pawn.h"
#include "UTGame.UTPlayerInput.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "UTGame.UTWeapon.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTConsolePlayerInput : public UTPlayerInput
	{
	public:
		ADD_STRUCT(float, HoverBoardPitchMultiplier, 1192)
		ADD_STRUCT(float, AutoPitchStopAdjustingValue, 1188)
		ADD_STRUCT(float, AutoPitchCenterSpeed, 1184)
		ADD_STRUCT(float, ViewAccel_BackToCenterSpeed, 1180)
		ADD_STRUCT(float, ViewAccel_BackToCenterBoundary, 1176)
		ADD_STRUCT(float, ViewAccel_LookingUpOrDownBoundary, 1172)
		ADD_STRUCT(float, ViewAccel_PitchThreshold, 1168)
		ADD_STRUCT(float, ViewAccel_MaxTurnSpeed, 1164)
		ADD_STRUCT(float, ViewAccel_RampSpeed, 1160)
		ADD_STRUCT(float, MagicScaleForSensitivityEdge, 1156)
		ADD_STRUCT(float, MagicScaleForSensitivityMiddle, 1152)
		ADD_STRUCT(float, RightThumbStickDeadZoneThreshold, 1148)
		ADD_STRUCT(float, LeftThumbStickDeadZoneThreshold, 1144)
		ADD_STRUCT(Object::Rotator, LastDeltaRot, 1132)
		ADD_STRUCT(Object::Vector, LastCamLoc, 1120)
		ADD_STRUCT(float, LastAdjustZ, 1116)
		ADD_STRUCT(float, LastAdjustY, 1112)
		ADD_STRUCT(float, LastDistFromAimZa, 1108)
		ADD_STRUCT(float, LastDistFromAimYa, 1104)
		ADD_STRUCT(float, LastTargetHeight, 1100)
		ADD_STRUCT(float, LastTargetRadius, 1096)
		ADD_STRUCT(float, LastAdhesionAmtZ, 1092)
		ADD_STRUCT(float, LastAdhesionAmtY, 1088)
		ADD_STRUCT(float, LastFrictionMultiplier, 1084)
		ADD_STRUCT(float, LastDistFromAimY, 1080)
		ADD_STRUCT(float, LastDistFromAimZ, 1076)
		ADD_STRUCT(float, LastDistMultiplier, 1072)
		ADD_STRUCT(float, LastDistToTarget, 1068)
		ADD_STRUCT(float, LastFrictionTargetTime, 1064)
		ADD_OBJECT(Pawn, LastFrictionTarget, 1060)
		ADD_STRUCT(float, Dodge_Threshold, 1056)
		ADD_STRUCT(float, ViewAccel_Twitchy, 1052)
		ADD_STRUCT(float, ViewAccel_TimeHeld, 1048)
		ADD_STRUCT(float, ViewAccel_TimeToHoldBeforeFastAcceleration, 1044)
		ADD_STRUCT(float, ViewAccel_CurrMutliplier, 1040)
		ADD_STRUCT(float, ViewAccel_BaseMultiplier, 1036)
		ADD_STRUCT(float, ViewAccel_DiagonalThreshold, 1032)
		ADD_STRUCT(float, ViewAccel_YawThreshold, 1028)
		ADD_STRUCT(float, SlowTurnScaling, 1024)
		ADD_STRUCT(float, AutoVehicleCenterSpeed, 1020)
		ADD_STRUCT(float, AutoCenterDelay, 1016)
		ADD_STRUCT(float, LastTurnTime, 1012)
		ADD_BOOL(bIsLookingDown, 1008, 0x100)
		ADD_BOOL(bIsLookingUp, 1008, 0x80)
		ADD_BOOL(bAppliedTargetFriction, 1008, 0x40)
		ADD_BOOL(bDebugTargetFriction, 1008, 0x20)
		ADD_BOOL(bTargetFrictionEnabled, 1008, 0x10)
		ADD_BOOL(bDebugViewAcceleration, 1008, 0x8)
		ADD_BOOL(bViewAccelerationEnabled, 1008, 0x4)
		ADD_BOOL(bAutoCenterVehiclePitch, 1008, 0x2)
		ADD_BOOL(bAutoCenterPitch, 1008, 0x1)
		ADD_STRUCT(float, TurningAccelerationMultiplier, 1004)
		ADD_STRUCT(float, SensitivityMultiplier, 1000)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.PreProcessInput");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyViewAutoPitchCentering(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyViewAutoPitchCentering");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyViewAutoVehiclePitchCentering(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyViewAutoVehiclePitchCentering");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyViewAcceleration(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyViewAcceleration");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyTargetAdhesion(float DeltaTime, class UTWeapon* W, int& out_YawRot, int& out_PitchRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyTargetAdhesion");
			byte params[16] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(class UTWeapon**)&params[4] = W;
			*(int*)&params[8] = out_YawRot;
			*(int*)&params[12] = out_PitchRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YawRot = *(int*)&params[8];
			out_PitchRot = *(int*)&params[12];
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.AdjustMouseSensitivity");
			byte params[4] = { NULL };
			*(float*)&params[0] = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyTargetFriction(float DeltaTime, class UTWeapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.ApplyTargetFriction");
			byte params[8] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(class UTWeapon**)&params[4] = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Actor::EDoubleClickDir CheckForDoubleClickMove(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTConsolePlayerInput.CheckForDoubleClickMove");
			byte params[5] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::EDoubleClickDir*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
