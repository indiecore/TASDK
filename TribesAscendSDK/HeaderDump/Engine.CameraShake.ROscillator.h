#pragma once
#include "Engine.CameraShake.FOscillator.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CameraShake.ROscillator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ROscillator
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<FOscillator>, Pitch, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FOscillator>, Yaw, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FOscillator>, Roll, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
