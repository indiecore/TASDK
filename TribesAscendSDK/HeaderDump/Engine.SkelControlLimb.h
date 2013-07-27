#pragma once
#include "Engine.SkelControlBase.h"
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
	class SkelControlLimb : public SkelControlBase
	{
	public:
		ADD_STRUCT(ScriptName, StretchRollBoneName, 244)
		ADD_STRUCT(Object::Vector2D, StretchLimits, 236)
		ADD_BOOL(bAllowStretching, 232, 0x20)
		ADD_BOOL(bTakeRotationFromEffectorSpace, 232, 0x10)
		ADD_BOOL(bMaintainEffectorRelRot, 232, 0x8)
		ADD_BOOL(bRotateJoint, 232, 0x4)
		ADD_BOOL(bInvertJointAxis, 232, 0x2)
		ADD_BOOL(bInvertBoneAxis, 232, 0x1)
		ADD_STRUCT(ScriptName, JointTargetSpaceBoneName, 224)
		ADD_STRUCT(Object::Vector, JointTargetLocation, 212)
		ADD_STRUCT(ScriptName, EffectorSpaceBoneName, 204)
		ADD_STRUCT(Object::EAxis, JointAxis, 203)
		ADD_STRUCT(Object::EAxis, BoneAxis, 202)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, JointTargetLocationSpace, 201)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, EffectorLocationSpace, 200)
		ADD_STRUCT(Object::Vector, EffectorLocation, 188)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
