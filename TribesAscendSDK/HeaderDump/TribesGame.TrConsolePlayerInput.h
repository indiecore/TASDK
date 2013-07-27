#pragma once
#include "Engine.Pawn.h"
#include "TribesGame.TrPlayerInput.h"
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
	class TrConsolePlayerInput : public TrPlayerInput
	{
	public:
		ADD_STRUCT(float, HoverBoardPitchMultiplier, 648)
		ADD_STRUCT(float, AutoPitchStopAdjustingValue, 644)
		ADD_STRUCT(float, AutoPitchCenterSpeed, 640)
		ADD_STRUCT(float, ViewAccel_BackToCenterSpeed, 636)
		ADD_STRUCT(float, ViewAccel_BackToCenterBoundary, 632)
		ADD_STRUCT(float, ViewAccel_LookingUpOrDownBoundary, 628)
		ADD_STRUCT(float, ViewAccel_PitchThreshold, 624)
		ADD_STRUCT(float, ViewAccel_MaxTurnSpeed, 620)
		ADD_STRUCT(float, ViewAccel_RampSpeed, 616)
		ADD_STRUCT(float, MagicScaleForSensitivityEdge, 612)
		ADD_STRUCT(float, MagicScaleForSensitivityMiddle, 608)
		ADD_STRUCT(float, RightThumbStickDeadZoneThreshold, 604)
		ADD_STRUCT(float, LeftThumbStickDeadZoneThreshold, 600)
		ADD_STRUCT(Rotator, LastDeltaRot, 588)
		ADD_STRUCT(Vector, LastCamLoc, 576)
		ADD_STRUCT(float, LastAdjustZ, 572)
		ADD_STRUCT(float, LastAdjustY, 568)
		ADD_STRUCT(float, LastDistFromAimZa, 564)
		ADD_STRUCT(float, LastDistFromAimYa, 560)
		ADD_STRUCT(float, LastTargetHeight, 556)
		ADD_STRUCT(float, LastTargetRadius, 552)
		ADD_STRUCT(float, LastAdhesionAmtZ, 548)
		ADD_STRUCT(float, LastAdhesionAmtY, 544)
		ADD_STRUCT(float, LastFrictionMultiplier, 540)
		ADD_STRUCT(float, LastDistFromAimY, 536)
		ADD_STRUCT(float, LastDistFromAimZ, 532)
		ADD_STRUCT(float, LastDistMultiplier, 528)
		ADD_STRUCT(float, LastDistToTarget, 524)
		ADD_STRUCT(float, LastFrictionTargetTime, 520)
		ADD_OBJECT(Pawn, LastFrictionTarget, 516)
		ADD_STRUCT(float, Dodge_Threshold, 512)
		ADD_STRUCT(float, ViewAccel_Twitchy, 508)
		ADD_STRUCT(float, ViewAccel_TimeHeld, 504)
		ADD_STRUCT(float, ViewAccel_TimeToHoldBeforeFastAcceleration, 500)
		ADD_STRUCT(float, ViewAccel_CurrMutliplier, 496)
		ADD_STRUCT(float, ViewAccel_BaseMultiplier, 492)
		ADD_STRUCT(float, ViewAccel_DiagonalThreshold, 488)
		ADD_STRUCT(float, ViewAccel_YawThreshold, 484)
		ADD_STRUCT(float, SlowTurnScaling, 480)
		ADD_STRUCT(float, AutoVehicleCenterSpeed, 476)
		ADD_STRUCT(float, AutoCenterDelay, 472)
		ADD_STRUCT(float, LastTurnTime, 468)
		ADD_BOOL(bIsLookingDown, 464, 0x100)
		ADD_BOOL(bIsLookingUp, 464, 0x80)
		ADD_BOOL(bAppliedTargetFriction, 464, 0x40)
		ADD_BOOL(bDebugTargetFriction, 464, 0x20)
		ADD_BOOL(bTargetFrictionEnabled, 464, 0x10)
		ADD_BOOL(bDebugViewAcceleration, 464, 0x8)
		ADD_BOOL(bViewAccelerationEnabled, 464, 0x4)
		ADD_BOOL(bAutoCenterVehiclePitch, 464, 0x2)
		ADD_BOOL(bAutoCenterPitch, 464, 0x1)
		ADD_STRUCT(float, TurningAccelerationMultiplier, 460)
		ADD_STRUCT(float, SensitivityMultiplier, 456)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78083);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78084);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyViewAutoPitchCentering(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78088);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyViewAutoVehiclePitchCentering(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78092);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyViewAcceleration(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78100);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyTargetAdhesion(float DeltaTime, class UTWeapon* W, int& out_YawRot, int& out_PitchRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78104);
			byte params[16] = { NULL };
			*(float*)params = DeltaTime;
			*(class UTWeapon**)&params[4] = W;
			*(int*)&params[8] = out_YawRot;
			*(int*)&params[12] = out_PitchRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YawRot = *(int*)&params[8];
			out_PitchRot = *(int*)&params[12];
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78132);
			byte params[4] = { NULL };
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyTargetFriction(float DeltaTime, class UTWeapon* W)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78134);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			*(class UTWeapon**)&params[4] = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Actor::EDoubleClickDir CheckForDoubleClickMove(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78154);
			byte params[5] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::EDoubleClickDir*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
