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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18230);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUserClosedAdvertisement()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18233);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18237);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowBanner(bool bShowBottomOfScreen)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18238);
			byte params[4] = { NULL };
			*(bool*)params = bShowBottomOfScreen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideBanner()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18240);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceCloseAd()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18241);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPauseWhileAdOpen(bool bShouldPause)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18242);
			byte params[4] = { NULL };
			*(bool*)params = bShouldPause;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddClickedBannerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18244);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearClickedBannerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18246);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddClosedAdDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18249);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearClosedAdDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18251);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
