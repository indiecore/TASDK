#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTCharInfo.CustomAIData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CustomAIData
	{
	public:
		ADD_VAR(::StrProperty, FavoriteWeapon, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReactionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Jumpiness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CombatStyle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Aggressiveness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Accuracy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StrafingAbility, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Tactics, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
