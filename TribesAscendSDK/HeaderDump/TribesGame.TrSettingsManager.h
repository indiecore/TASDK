#pragma once
#include "Core.Object.h"
#include "TribesGame.TrRegionSettings.h"
#include "TribesGame.TrVideoSettings.h"
#include "TribesGame.TrAudioSettings.h"
#include "TribesGame.GFxTrMenuMoviePlayer.h"
#include "TribesGame.TrHUDSettings.h"
#include "TribesGame.TrControlSettings.h"
#include "TribesGame.TrKeyBindings.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrSettingsManager : public Object
	{
	public:
		ADD_OBJECT(TrRegionSettings, RegionSettings, 76)
		ADD_OBJECT(TrAudioSettings, AudioSettings, 68)
		ADD_OBJECT(TrControlSettings, ControlSettings, 80)
		ADD_OBJECT(TrKeyBindings, KeyBindings, 64)
		ADD_OBJECT(TrHUDSettings, HUDSettings, 60)
		ADD_OBJECT(TrVideoSettings, VideoSettings, 72)
		ADD_OBJECT(GFxTrMenuMoviePlayer, MP, 84)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112354);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
