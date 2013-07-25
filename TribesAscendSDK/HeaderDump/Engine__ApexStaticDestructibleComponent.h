#pragma once
#include "Engine__ApexStaticComponent.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ApexDestructiblePreview'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ApexDestructibleActor'!
		ADD_VAR(::FloatProperty, SleepDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SleepEnergyThreshold, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
