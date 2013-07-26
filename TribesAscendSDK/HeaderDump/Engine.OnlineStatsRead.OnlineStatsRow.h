#pragma once
#include "Engine.Settings.SettingsData.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineStatsRead.OnlineStatsRow." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineStatsRead.OnlineStatsRow." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsRow
	{
	public:
		ADD_VAR(::StrProperty, NickName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<SettingsData>, Rank, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PlayerID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
