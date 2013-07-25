#pragma once
#include "Engine__Volume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ReverbVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ReverbVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ReverbVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ReverbVolume : public Volume
	{
	public:
		ADD_OBJECT(ReverbVolume, NextLowerPriorityVolume)
		// WARNING: Unknown structure type 'ScriptStruct Engine.ReverbVolume.InteriorSettings' for the property named 'AmbientZoneSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ReverbVolume.ReverbSettings' for the property named 'Settings'!
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::FloatProperty, Priority, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
