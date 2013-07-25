#pragma once
#include "Engine__AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeBlendDirectional." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimNodeBlendDirectional." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendDirectional : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::BoolProperty, bUseAcceleration, 0x1)
		ADD_STRUCT(::RotatorProperty, RotationOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SingleAnimAtOrAboveLOD, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirDegreesPerSecond, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
