#pragma once
#include "Engine.EngineTypes.LightmassLightSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.LightmassDirectionalLightSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassDirectionalLightSettings : public LightmassLightSettings
	{
	public:
		ADD_VAR(::FloatProperty, LightSourceAngle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
