#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameplayEvents.PlayerInformationNew." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameplayEvents.PlayerInformationNew." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerInformationNew
	{
	public:
		ADD_VAR(::BoolProperty, bIsBot, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, UniqueId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ControllerName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
