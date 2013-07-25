#pragma once
#include "Engine.MapInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKMapInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKMapInfo : public MapInfo
	{
	public:
		ADD_VAR(::FloatProperty, VisibilityModifier, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
