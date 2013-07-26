#pragma once
#include "Engine.FogVolumeDensityComponent.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FogVolumeSphericalDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FogVolumeSphericalDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FogVolumeSphericalDensityComponent : public FogVolumeDensityComponent
	{
	public:
		ADD_VAR(::FloatProperty, SphereRadius, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SphereCenter, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDensity, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
