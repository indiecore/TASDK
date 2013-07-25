#pragma once
#include "TribesGame__GFxTrMenuMoviePlayer.h"
#include "Core__Object.h"
#include "TribesGame__TrRegionSettings.h"
#include "TribesGame__TrKeyBindings.h"
#include "TribesGame__TrAudioSettings.h"
#include "TribesGame__TrControlSettings.h"
#include "TribesGame__TrVideoSettings.h"
#include "TribesGame__TrHUDSettings.h"
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
		// Here lies the not-yet-implemented method 'Initialize'
	};
}
#undef ADD_OBJECT
