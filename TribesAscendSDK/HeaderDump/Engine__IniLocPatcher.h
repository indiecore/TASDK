#pragma once
#include "Core__Object.h"
namespace UnrealScript
{
	class IniLocPatcher : public Object
	{
	public:
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.OnReadTitleFileComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bWasSuccessful;
			*(ScriptArray<wchar_t>*)(params + 4) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DownloadFiles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.DownloadFiles");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadFileComplete(bool bWasSuccessful, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.OnReadFileComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bWasSuccessful;
			*(ScriptArray<wchar_t>*)(params + 4) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessIniLocFile(ScriptArray<wchar_t> Filename, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& FileData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.ProcessIniLocFile");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Filename;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = FileData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FileData = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
		}
		void AddFileToDownload(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.AddFileToDownload");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadFileDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.AddReadFileDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadFileDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.ClearReadFileDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearCachedFiles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.ClearCachedFiles");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> UpdateLocFileName(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.IniLocPatcher.UpdateLocFileName");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
