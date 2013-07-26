#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrQueueManager.ServerConfig." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ServerConfig
	{
	public:
		ADD_VAR(::StrProperty, ServerName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCanExpire, 0x8)
		ADD_VAR(::BoolProperty, bActive, 0x4)
		ADD_VAR(::BoolProperty, bOwner, 0x2)
		ADD_VAR(::BoolProperty, bOpen, 0x1)
		ADD_VAR(::IntProperty, MinutesRented, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MatchQueueId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActiveConfig, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
