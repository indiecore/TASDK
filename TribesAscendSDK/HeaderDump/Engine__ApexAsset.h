#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexAsset : public Object
	{
	public:
		ADD_VAR(::StrProperty, SourceFilePath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OriginalApexName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
