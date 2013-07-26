#pragma once
#include "Core.Object.Vector.h"
#include "Engine.SkelControlBase.h"
#include "Core.Object.Vector2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlLimb." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkelControlLimb." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlLimb : public SkelControlBase
	{
	public:
		ADD_VAR(::NameProperty, StretchRollBoneName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, StretchLimits, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllowStretching, 0x20)
		ADD_VAR(::BoolProperty, bTakeRotationFromEffectorSpace, 0x10)
		ADD_VAR(::BoolProperty, bMaintainEffectorRelRot, 0x8)
		ADD_VAR(::BoolProperty, bRotateJoint, 0x4)
		ADD_VAR(::BoolProperty, bInvertJointAxis, 0x2)
		ADD_VAR(::BoolProperty, bInvertBoneAxis, 0x1)
		ADD_VAR(::NameProperty, JointTargetSpaceBoneName, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, JointTargetLocation, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EffectorSpaceBoneName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, JointAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BoneAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, JointTargetLocationSpace, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EffectorLocationSpace, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EffectorLocation, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
