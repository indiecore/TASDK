#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameStateObject.PlayerState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerState
	{
	public:
		ADD_VAR(::FloatProperty, TimeAliveSinceLastDeath, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeSpawned, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentTeamIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
