#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
namespace UnrealScript
{
	class OnlineTitleFileInterface : public Interface
	{
	public:
		bool ReadTitleFile(ScriptString* FileToRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18269);
			byte params[16] = { NULL };
			*(ScriptString**)params = FileToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetTitleFileContents(ScriptString* Filename, ScriptArray<byte>& FileContents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18277);
			byte params[28] = { NULL };
			*(ScriptString**)params = Filename;
			*(ScriptArray<byte>*)&params[12] = FileContents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileContents = *(ScriptArray<byte>*)&params[12];
			return *(bool*)&params[24];
		}
		bool ClearDownloadedFiles()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18292);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22967);
			byte params[16] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22972);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22974);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetTitleFileState(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22979);
			byte params[13] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[12];
		}
		bool ClearDownloadedFile(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22982);
			byte params[16] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
