#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DownloadableContentEnumerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DownloadableContentEnumerator : public Object
	{
	public:
		ADD_VAR(::StrProperty, DLCRootDir, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
