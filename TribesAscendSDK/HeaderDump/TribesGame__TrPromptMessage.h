#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPromptMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPromptMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPromptMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, YourJackalGrenadesHaveBeenDestroyed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnterVehicle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ObjectiveUpgradeDeniedMaxLevel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ObjectiveUpgradeDeniedNoCredits, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KickWarning, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UpgradeObjective, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EquipRepairGun, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, UpgradeDeniedSound)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
