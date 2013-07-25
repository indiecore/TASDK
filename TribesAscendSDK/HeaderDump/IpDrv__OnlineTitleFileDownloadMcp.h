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
	};
}
#undef ADD_VAR
