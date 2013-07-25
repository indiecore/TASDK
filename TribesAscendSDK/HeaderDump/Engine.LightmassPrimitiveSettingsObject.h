#pragma once
#include "Core.Object.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightmassPrimitiveSettings' for the property named 'LightmassSettings'!
	};
}
#undef ADD_STRUCT
