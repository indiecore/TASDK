#pragma once
#include "Core.Object.Quat.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.BoneAtom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.BoneAtom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BoneAtom
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Quat>, Rotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Translation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
