#pragma once
#include "Core.Object.h"
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
		void OnUserClickedBanner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.OnUserClickedBanner");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUserClosedAdvertisement()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.OnUserClosedAdvertisement");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowBanner(bool bShowBottomOfScreen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.ShowBanner");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShowBottomOfScreen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideBanner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.HideBanner");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceCloseAd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.ForceCloseAd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPauseWhileAdOpen(bool bShouldPause)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.SetPauseWhileAdOpen");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShouldPause;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddClickedBannerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.AddClickedBannerDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearClickedBannerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.ClearClickedBannerDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddClosedAdDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.AddClosedAdDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearClosedAdDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.ClearClosedAdDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
