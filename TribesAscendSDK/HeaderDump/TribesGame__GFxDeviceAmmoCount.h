#pragma once
#include "GFxUI__GFxMoviePlayer.h"
#include "Engine__LocalPlayer.h"
#include "GFxUI__GFxObject.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxDeviceAmmoCount." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxDeviceAmmoCount : public GFxMoviePlayer
	{
	public:
		ADD_OBJECT(GFxObject, AmmoCountTF)
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxDeviceAmmoCount.Init");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
