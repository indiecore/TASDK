#pragma once
#include "Engine.EngineTypes.LightmassLightSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.LightmassPointLightSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassPointLightSettings : public LightmassLightSettings
	{
	public:
		ADD_VAR(::FloatProperty, LightSourceRadius, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
