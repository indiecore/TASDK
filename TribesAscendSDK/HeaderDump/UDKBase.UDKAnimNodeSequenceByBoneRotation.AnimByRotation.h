#pragma once
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKAnimNodeSequenceByBoneRotation.AnimByRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKAnimNodeSequenceByBoneRotation.AnimByRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimByRotation
	{
	public:
		ADD_VAR(::NameProperty, AnimName, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, DesiredRotation, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
