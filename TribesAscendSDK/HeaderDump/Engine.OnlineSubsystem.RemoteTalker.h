#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.RemoteTalker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.RemoteTalker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RemoteTalker
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, TalkerId, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastNotificationTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasTalking, 0x1)
		ADD_VAR(::BoolProperty, bIsTalking, 0x2)
		ADD_VAR(::BoolProperty, bIsRegistered, 0x4)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
