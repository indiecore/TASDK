#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCharInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTCharInfo : public Object
	{
	public:
		ADD_VAR(::FloatProperty, LOD3DisplayFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LOD2DisplayFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LOD1DisplayFactor, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'FindFamilyInfo'
		// Here lies the not-yet-implemented method 'GetRandomCharClassName'
	};
}
#undef ADD_VAR
