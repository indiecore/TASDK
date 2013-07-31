#pragma once
#include "IpDrv.MCPBase.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineTitleFileDownloadMcp : public MCPBase
	{
	public:
		struct TitleFileMcp : public TitleFile
		{
		public:
			ADD_STRUCT(Object::Pointer, HttpDownloader, 28)
		};
		struct FileNameToURLMapping
		{
		public:
			ADD_STRUCT(ScriptName, UrlMapping, 8)
			ADD_STRUCT(ScriptName, Filename, 0)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, ReadTitleFileCompleteDelegates, 64)
		ADD_STRUCT(ScriptArray<OnlineTitleFileDownloadMcp::TitleFileMcp>, TitleFiles, 76)
		ADD_STRUCT(ScriptArray<OnlineTitleFileDownloadMcp::FileNameToURLMapping>, FilesToUrls, 108)
		ADD_STRUCT(float, TimeOut, 104)
		ADD_STRUCT(ScriptString*, BaseUrl, 92)
		ADD_STRUCT(int, DownloadCount, 88)
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33846);
			byte params[16] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadTitleFile(ScriptString* FileToRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33862);
			byte params[16] = { NULL };
			*(ScriptString**)params = FileToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33865);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33867);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetTitleFileContents(ScriptString* Filename, ScriptArray<byte>& FileContents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33870);
			byte params[28] = { NULL };
			*(ScriptString**)params = Filename;
			*(ScriptArray<byte>*)&params[12] = FileContents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileContents = *(ScriptArray<byte>*)&params[12];
			return *(bool*)&params[24];
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetTitleFileState(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33875);
			byte params[13] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[12];
		}
		bool ClearDownloadedFiles()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33879);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ClearDownloadedFile(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33881);
			byte params[16] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_STRUCT
