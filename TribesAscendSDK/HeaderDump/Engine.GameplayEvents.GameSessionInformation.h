#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameplayEvents.GameSessionInformation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameplayEvents.GameSessionInformation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameSessionInformation
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, OwningNetId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GameTypeId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SessionInstance, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapURL, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameplaySessionID, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGameplaySessionInProgress, 0x1)
		ADD_VAR(::FloatProperty, GameplaySessionEndTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GameplaySessionStartTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameplaySessionTimestamp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Language, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlatformType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AppTitleID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
