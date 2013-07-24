#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrSettingsManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrSettingsManager : public Object
	{
	public:
		ADD_OBJECT(TrRegionSettings, RegionSettings)
		ADD_OBJECT(TrAudioSettings, AudioSettings)
		ADD_OBJECT(TrControlSettings, ControlSettings)
		ADD_OBJECT(TrKeyBindings, KeyBindings)
		ADD_OBJECT(TrHUDSettings, HUDSettings)
		ADD_OBJECT(TrVideoSettings, VideoSettings)
		ADD_OBJECT(GFxTrMenuMoviePlayer, MP)
	};
}
#undef ADD_OBJECT
