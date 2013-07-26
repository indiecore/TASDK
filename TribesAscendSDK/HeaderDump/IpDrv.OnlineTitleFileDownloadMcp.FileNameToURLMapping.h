#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineTitleFileDownloadMcp.FileNameToURLMapping." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FileNameToURLMapping
	{
	public:
		ADD_VAR(::NameProperty, UrlMapping, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Filename, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
