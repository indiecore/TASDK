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
		// Here lies the not-yet-implemented method 'Init'
	};
}
#undef ADD_OBJECT
