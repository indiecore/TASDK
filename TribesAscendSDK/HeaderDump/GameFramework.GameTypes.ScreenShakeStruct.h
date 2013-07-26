#pragma once
#include "Core.Object.Vector.h"
#include "GameFramework.GameTypes.ShakeParams.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameTypes.ScreenShakeStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameTypes.ScreenShakeStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScreenShakeStruct
	{
	public:
		ADD_VAR(::FloatProperty, TimeToGo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeDuration, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RotAmplitude, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RotFrequency, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RotSinOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ShakeParams>, RotParam, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocAmplitude, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocFrequency, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocSinOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ShakeParams>, LocParam, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOVAmplitude, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOVFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOVSinOffset, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FOVParam, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ShakeName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOverrideTargetingDampening, 0x1)
		ADD_VAR(::FloatProperty, TargetingDampening, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
