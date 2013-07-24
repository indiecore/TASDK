#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTimerMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTimerMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTimerMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, TimerMessage, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_sOneMinuteWarningBE)
		ADD_OBJECT(SoundCue, m_sFiveMinuteWarningBE)
		ADD_OBJECT(SoundCue, m_sOneMinuteWarningDS)
		ADD_OBJECT(SoundCue, m_sFiveMinuteWarningDS)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
