#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CoverLink.DynamicLinkInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DynamicLinkInfo
	{
	public:
		ADD_STRUCT(::VectorProperty, LastSrcLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastTargetLocation, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
