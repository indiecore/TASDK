#pragma once
#include "Engine.FogVolumeDensityComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FogVolumeConstantDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FogVolumeConstantDensityComponent : public FogVolumeDensityComponent
	{
	public:
		ADD_VAR(::FloatProperty, Density, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
