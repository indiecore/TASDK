#pragma once
#include "Engine.SkelControlSingleBone.h"
#include "Core.Object.h"
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
	class UDKSkelControl_TurretConstrained : public SkelControlSingleBone
	{
	public:
		struct TurretConstraintData
		{
		public:
			ADD_STRUCT(int, RollConstraint, 8)
			ADD_STRUCT(int, YawConstraint, 4)
			ADD_STRUCT(int, PitchConstraint, 0)
		};
		struct TurretStepData
		{
		public:
			ADD_STRUCT(UDKSkelControl_TurretConstrained::TurretConstraintData, MinAngle, 20)
			ADD_STRUCT(UDKSkelControl_TurretConstrained::TurretConstraintData, MaxAngle, 8)
			ADD_STRUCT(int, StepEndAngle, 4)
			ADD_STRUCT(int, StepStartAngle, 0)
		};
		ADD_STRUCT(ScriptArray<UDKSkelControl_TurretConstrained::TurretStepData>, Steps, 264)
		ADD_STRUCT(Rotator, ConstrainedBoneRotation, 300)
		ADD_STRUCT(int, AssociatedSeatIndex, 296)
		ADD_STRUCT(Rotator, DesiredBoneRotation, 284)
		ADD_STRUCT(float, PitchSpeedScale, 280)
		ADD_STRUCT(float, LagDegreesPerSecond, 276)
		ADD_STRUCT(UDKSkelControl_TurretConstrained::TurretConstraintData, MinAngle, 252)
		ADD_STRUCT(UDKSkelControl_TurretConstrained::TurretConstraintData, MaxAngle, 240)
		ADD_BOOL(bIsInMotion, 236, 0x100)
		ADD_BOOL(bResetWhenUnattended, 236, 0x80)
		ADD_BOOL(bFixedWhenFiring, 236, 0x40)
		ADD_BOOL(bInvertRoll, 236, 0x20)
		ADD_BOOL(bInvertYaw, 236, 0x10)
		ADD_BOOL(bInvertPitch, 236, 0x8)
		ADD_BOOL(bConstrainRoll, 236, 0x4)
		ADD_BOOL(bConstrainYaw, 236, 0x2)
		ADD_BOOL(bConstrainPitch, 236, 0x1)
		void OnTurretStatusChange(bool bIsMoving)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35459);
			byte params[4] = { NULL };
			*(bool*)params = bIsMoving;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitTurret(Rotator InitRot, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35485);
			byte params[16] = { NULL };
			*(Rotator*)params = InitRot;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[12] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WouldConstrainPitch(int TestPitch, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35488);
			byte params[12] = { NULL };
			*(int*)params = TestPitch;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
