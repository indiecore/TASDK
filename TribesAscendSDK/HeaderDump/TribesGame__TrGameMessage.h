#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundCue, m_sMatchStartDiamondSword)
		ADD_OBJECT(SoundCue, m_sMatchStartBloodEagle)
		ADD_VAR(::StrProperty, WaitingForPlayers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OvertimeNotification, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreOnDiamondSwordMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreOnBloodEagleMessage, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
