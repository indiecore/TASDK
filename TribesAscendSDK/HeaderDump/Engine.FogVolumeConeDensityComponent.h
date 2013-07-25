#pragma once
#include "Engine.FogVolumeDensityComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FogVolumeConeDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FogVolumeConeDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FogVolumeConeDensityComponent : public FogVolumeDensityComponent
	{
	public:
		ADD_VAR(::FloatProperty, ConeMaxAngle, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ConeAxis, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConeRadius, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ConeVertex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDensity, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
