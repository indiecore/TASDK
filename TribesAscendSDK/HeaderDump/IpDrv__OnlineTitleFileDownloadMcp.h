#pragma once
#include "IpDrv__MCPBase.h"
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
		// Here lies the not-yet-implemented method 'OnReadTitleFileComplete'
		// Here lies the not-yet-implemented method 'ReadTitleFile'
		// Here lies the not-yet-implemented method 'AddReadTitleFileCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearReadTitleFileCompleteDelegate'
		// Here lies the not-yet-implemented method 'GetTitleFileContents'
		// Here lies the not-yet-implemented method 'GetTitleFileState'
		// Here lies the not-yet-implemented method 'ClearDownloadedFiles'
		// Here lies the not-yet-implemented method 'ClearDownloadedFile'
	};
}
#undef ADD_VAR
