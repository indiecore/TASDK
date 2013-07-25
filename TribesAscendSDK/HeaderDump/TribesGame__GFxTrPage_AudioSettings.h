#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_AudioSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_AudioSettings : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bWaitingForAudioEntry, 0x1)
		ADD_VAR(::IntProperty, AudioIndex, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'SetSubTitle'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
	};
}
#undef ADD_VAR
