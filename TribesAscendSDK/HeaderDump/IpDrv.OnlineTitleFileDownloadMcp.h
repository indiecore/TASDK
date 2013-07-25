#pragma once
#include "IpDrv.MCPBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineTitleFileDownloadMcp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineTitleFileDownloadMcp : public MCPBase
	{
	public:
		ADD_VAR(::FloatProperty, TimeOut, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BaseUrl, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DownloadCount, 0xFFFFFFFF)
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.OnReadTitleFileComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bWasSuccessful;
			*(ScriptArray<wchar_t>*)(params + 4) = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadTitleFile(ScriptArray<wchar_t> FileToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ReadTitleFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = FileToRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddReadTitleFileCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadTitleFileCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.AddReadTitleFileCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ClearReadTitleFileCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadTitleFileCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetTitleFileContents(ScriptArray<wchar_t> Filename, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& FileContents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.GetTitleFileContents");
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
		byte GetTitleFileState(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.GetTitleFileState");
			byte* params = (byte*)malloc(13);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 12);
			free(params);
			return returnVal;
		}
		bool ClearDownloadedFiles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ClearDownloadedFiles");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ClearDownloadedFile(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineTitleFileDownloadMcp.ClearDownloadedFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
