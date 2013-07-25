#pragma once
#include "Engine__SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_LockRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKSkelControl_LockRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_LockRotation : public SkelControlBase
	{
	public:
		ADD_VAR(::NameProperty, RotationSpaceBoneName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LockRotationSpace, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, MaxDelta, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LockRotation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLockRoll, 0x4)
		ADD_VAR(::BoolProperty, bLockYaw, 0x2)
		ADD_VAR(::BoolProperty, bLockPitch, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
