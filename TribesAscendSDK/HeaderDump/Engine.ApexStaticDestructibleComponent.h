#pragma once
#include "Engine.ApexStaticComponent.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexStaticDestructibleComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ApexStaticDestructibleComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexStaticDestructibleComponent : public ApexStaticComponent
	{
	public:
		ADD_VAR(::BoolProperty, bIsThumbnailComponent, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ApexDestructiblePreview, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ApexDestructibleActor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SleepDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SleepEnergyThreshold, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
