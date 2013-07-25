#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DownloadableContentEnumerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DownloadableContentEnumerator : public Object
	{
	public:
		ADD_VAR(::StrProperty, DLCRootDir, 0xFFFFFFFF)
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
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFindDLCDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.ClearFindDLCDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DeleteDLC(ScriptArray<wchar_t> DLCName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.DeleteDLC");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = DLCName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InstallAllDLC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.InstallAllDLC");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstallDLC(ScriptArray<wchar_t> DLCName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.InstallDLC");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = DLCName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TriggerFindDLCDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentEnumerator.TriggerFindDLCDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
