#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InGameAdManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InGameAdManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bShouldPauseWhileAdOpen, 0x1)
		// Here lies the not-yet-implemented method 'OnUserClickedBanner'
		// Here lies the not-yet-implemented method 'OnUserClosedAdvertisement'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'ShowBanner'
		// Here lies the not-yet-implemented method 'HideBanner'
		// Here lies the not-yet-implemented method 'ForceCloseAd'
		// Here lies the not-yet-implemented method 'SetPauseWhileAdOpen'
		// Here lies the not-yet-implemented method 'AddClickedBannerDelegate'
		// Here lies the not-yet-implemented method 'ClearClickedBannerDelegate'
		// Here lies the not-yet-implemented method 'AddClosedAdDelegate'
		// Here lies the not-yet-implemented method 'ClearClosedAdDelegate'
	};
}
#undef ADD_VAR
