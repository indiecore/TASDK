#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAudioSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAudioSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAudioSettings : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, m_nVolumeMaster, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeMusic, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeVoice, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeVGS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeEffects, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, m_SettingsList)
		ADD_VAR(::IntProperty, m_SettingsCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
