#pragma once
#include "Engine.CameraShake.FOscillator.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CameraShake.VOscillator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VOscillator
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<FOscillator>, X, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FOscillator>, Y, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FOscillator>, Z, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
