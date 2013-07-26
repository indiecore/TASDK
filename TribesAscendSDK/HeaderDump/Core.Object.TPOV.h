#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.TPOV." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.TPOV." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TPOV
	{
	public:
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOV, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
