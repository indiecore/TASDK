#pragma once
#include "Engine.Settings.SettingsData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineStatsRead.OnlineStatsColumn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineStatsRead.OnlineStatsColumn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsColumn
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<SettingsData>, StatValue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ColumnNo, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
