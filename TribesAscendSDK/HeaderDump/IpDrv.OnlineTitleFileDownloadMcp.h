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
		class TitleFileMcp : public TitleFile
		{
		public:
			ADD_STRUCT(Object::Pointer, HttpDownloader, 28)
		};
		class FileNameToURLMapping
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.OnReadTitleFileComplete");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadTitleFile(ScriptString* FileToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ReadTitleFile");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = FileToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.AddReadTitleFileCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ClearReadTitleFileCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetTitleFileContents(ScriptString* Filename, ScriptArray<byte>& FileContents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.GetTitleFileContents");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			*(ScriptArray<byte>*)&params[12] = FileContents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FileContents = *(ScriptArray<byte>*)&params[12];
			return *(bool*)&params[24];
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetTitleFileState(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.GetTitleFileState");
			byte params[13] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[12];
		}
		bool ClearDownloadedFiles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ClearDownloadedFiles");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ClearDownloadedFile(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ClearDownloadedFile");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_STRUCT
