#pragma once
#include "Engine.Volume.h"
#include "Engine.ReverbVolume.InteriorSettings.h"
#include "Engine.ReverbVolume.ReverbSettings.h"
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
		ADD_STRUCT(::NonArithmeticProperty<InteriorSettings>, AmbientZoneSettings, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ReverbSettings>, Settings, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::FloatProperty, Priority, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
