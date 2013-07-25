#pragma once
#include "Core__Interface.h"
namespace UnrealScript
{
	class OnlineTitleFileInterface : public Interface
	{
	public:
		bool ReadTitleFile(ScriptArray<wchar_t> FileToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.ReadTitleFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = FileToRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetTitleFileContents(ScriptArray<wchar_t> Filename, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& FileContents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.GetTitleFileContents");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Filename;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = FileContents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FileContents = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool ClearDownloadedFiles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.ClearDownloadedFiles");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.OnReadTitleFileComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bWasSuccessful;
			*(ScriptArray<wchar_t>*)(params + 4) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.AddReadTitleFileCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.ClearReadTitleFileCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetTitleFileState(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.GetTitleFileState");
			byte* params = (byte*)malloc(13);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 12);
			free(params);
			return returnVal;
		}
		bool ClearDownloadedFile(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineTitleFileInterface.ClearDownloadedFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
