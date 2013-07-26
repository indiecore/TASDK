#pragma once
#include "Core.Object.h"
#include "Engine.EngineTypes.LightmassPrimitiveSettings.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LightmassPrimitiveSettingsObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightmassPrimitiveSettingsObject : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<LightmassPrimitiveSettings>, LightmassSettings, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
