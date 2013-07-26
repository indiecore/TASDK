#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineGameplayEvents.GameplayEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameplayEvent
	{
	public:
		ADD_VAR(::IntProperty, EventNameAndDesc, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerEventAndTarget, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
