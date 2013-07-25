#pragma once
#include "Core.Object.h"
#include "TribesGame.TrRegionSettings.h"
#include "TribesGame.TrVideoSettings.h"
#include "TribesGame.TrAudioSettings.h"
#include "TribesGame.GFxTrMenuMoviePlayer.h"
#include "TribesGame.TrHUDSettings.h"
#include "TribesGame.TrControlSettings.h"
#include "TribesGame.TrKeyBindings.h"
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
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSettingsManager.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
