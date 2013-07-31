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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14683);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindDLC()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14686);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFindDLCDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14687);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFindDLCDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14689);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DeleteDLC(ScriptString* DLCName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14692);
			byte params[12] = { NULL };
			*(ScriptString**)params = DLCName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InstallAllDLC()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14694);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstallDLC(ScriptString* DLCName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14698);
			byte params[12] = { NULL };
			*(ScriptString**)params = DLCName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TriggerFindDLCDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14700);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
