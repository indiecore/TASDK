#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Quat.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNodeAimOffset.AimTransform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AimTransform
	{
	public:
		ADD_STRUCT(::VectorProperty, Translation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Quat>, Quaternion, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
