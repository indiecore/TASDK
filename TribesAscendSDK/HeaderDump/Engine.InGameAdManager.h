#pragma once
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InGameAdManager : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, ClickedBannerDelegates, 64)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, ClosedAdDelegates, 76)
		ADD_BOOL(bShouldPauseWhileAdOpen, 60, 0x1)
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShowBottomOfScreen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShouldPause;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddClickedBannerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.AddClickedBannerDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearClickedBannerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.ClearClickedBannerDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddClosedAdDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.AddClosedAdDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearClosedAdDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InGameAdManager.ClearClosedAdDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
