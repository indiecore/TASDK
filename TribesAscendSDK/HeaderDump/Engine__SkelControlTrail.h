#pragma once
#include "Engine__SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControlTrail." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkelControlTrail." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlTrail : public SkelControlBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'OldLocalToWorld'!
		ADD_VAR(::FloatProperty, ThisTimstep, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FakeVelocity, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, StretchLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TrailRelaxation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHadValidStrength, 0x8)
		ADD_VAR(::BoolProperty, bActorSpaceFakeVel, 0x4)
		ADD_VAR(::BoolProperty, bLimitStretch, 0x2)
		ADD_VAR(::BoolProperty, bInvertChainBoneAxis, 0x1)
		ADD_VAR(::ByteProperty, ChainBoneAxis, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ChainLength, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
