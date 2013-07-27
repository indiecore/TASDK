#pragma once
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
	class RB_ConstraintSetup : public Object
	{
	public:
		struct LinearDOFSetup
		{
		public:
			ADD_STRUCT(float, LimitSize, 4)
			ADD_STRUCT(byte, bLimited, 0)
		};
		ADD_STRUCT(ScriptName, JointName, 60)
		ADD_STRUCT(ScriptName, ConstraintBone1, 68)
		ADD_STRUCT(ScriptName, ConstraintBone2, 76)
		ADD_STRUCT(float, PulleyRatio, 252)
		ADD_STRUCT(float, AngularBreakThreshold, 248)
		ADD_STRUCT(float, TwistLimitDamping, 244)
		ADD_STRUCT(float, TwistLimitStiffness, 240)
		ADD_STRUCT(float, SwingLimitDamping, 236)
		ADD_STRUCT(float, SwingLimitStiffness, 232)
		ADD_STRUCT(float, TwistLimitAngle, 228)
		ADD_STRUCT(float, Swing2LimitAngle, 224)
		ADD_STRUCT(float, Swing1LimitAngle, 220)
		ADD_STRUCT(float, LinearBreakThreshold, 216)
		ADD_STRUCT(float, LinearLimitDamping, 212)
		ADD_STRUCT(float, LinearLimitStiffness, 208)
		ADD_STRUCT(RB_ConstraintSetup::LinearDOFSetup, LinearZSetup, 200)
		ADD_STRUCT(RB_ConstraintSetup::LinearDOFSetup, LinearYSetup, 192)
		ADD_STRUCT(RB_ConstraintSetup::LinearDOFSetup, LinearXSetup, 184)
		ADD_BOOL(bMaintainMinDistance, 180, 0x200)
		ADD_BOOL(bIsPulley, 180, 0x100)
		ADD_BOOL(bAngularBreakable, 180, 0x80)
		ADD_BOOL(bTwistLimitSoft, 180, 0x40)
		ADD_BOOL(bSwingLimitSoft, 180, 0x20)
		ADD_BOOL(bTwistLimited, 180, 0x10)
		ADD_BOOL(bSwingLimited, 180, 0x8)
		ADD_BOOL(bLinearBreakable, 180, 0x4)
		ADD_BOOL(bLinearLimitSoft, 180, 0x2)
		ADD_BOOL(bEnableProjection, 180, 0x1)
		ADD_STRUCT(Vector, PulleyPivot2, 168)
		ADD_STRUCT(Vector, PulleyPivot1, 156)
		ADD_STRUCT(Vector, SecAxis2, 144)
		ADD_STRUCT(Vector, PriAxis2, 132)
		ADD_STRUCT(Vector, Pos2, 120)
		ADD_STRUCT(Vector, SecAxis1, 108)
		ADD_STRUCT(Vector, PriAxis1, 96)
		ADD_STRUCT(Vector, Pos1, 84)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
