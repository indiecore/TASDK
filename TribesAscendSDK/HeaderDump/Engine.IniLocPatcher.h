#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class IniLocPatcher : public Object
	{
	public:
		struct IniLocFileEntry
		{
		public:
			ADD_STRUCT(OnlineSubsystem::EOnlineEnumerationReadState, ReadState, 12)
			ADD_STRUCT(ScriptString*, Filename, 0)
		};
		ADD_STRUCT(ScriptArray<IniLocPatcher::IniLocFileEntry>, Files, 60)
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18260);
			byte params[16] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18264);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DownloadFiles()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18267);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadFileComplete(bool bWasSuccessful, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18271);
			byte params[16] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessIniLocFile(ScriptString* Filename, ScriptArray<byte>& FileData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18279);
			byte params[24] = { NULL };
			*(ScriptString**)params = Filename;
			*(ScriptArray<byte>*)&params[12] = FileData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileData = *(ScriptArray<byte>*)&params[12];
		}
		void AddFileToDownload(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18283);
			byte params[12] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadFileDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18286);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadFileDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18288);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCachedFiles()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18290);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* UpdateLocFileName(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18294);
			byte params[24] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
	};
}
#undef ADD_STRUCT
