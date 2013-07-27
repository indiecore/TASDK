#pragma once
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DownloadableContentEnumerator : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem::OnlineContent>, DLCBundles, 60)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, FindDLCDelegates, 84)
		ADD_STRUCT(ScriptString*, DLCRootDir, 72)
		void OnFindDLCComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.OnFindDLCComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindDLC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.FindDLC");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFindDLCDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.AddFindDLCDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFindDLCDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.ClearFindDLCDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DeleteDLC(ScriptString* DLCName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.DeleteDLC");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = DLCName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InstallAllDLC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.InstallAllDLC");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstallDLC(ScriptString* DLCName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.InstallDLC");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = DLCName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerFindDLCDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.TriggerFindDLCDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
