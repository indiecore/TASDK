#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrQueueManager.ProfileConfig." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ProfileConfig
	{
	public:
		ADD_VAR(::StrProperty, PasswordPublic, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PasswordAdmin, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProfileDesc, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProfileName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, QueueCaseId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GameCaseId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Slots, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
