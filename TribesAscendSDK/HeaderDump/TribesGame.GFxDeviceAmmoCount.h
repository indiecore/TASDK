#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.GFxObject.h"
#include "Engine.LocalPlayer.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxDeviceAmmoCount : public GFxMoviePlayer
	{
	public:
		ADD_OBJECT(GFxObject, AmmoCountTF, 380)
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxDeviceAmmoCount.Init");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
