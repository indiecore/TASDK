#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameThirdPersonCameraMode.ViewOffsetData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ViewOffsetData
	{
	public:
		ADD_STRUCT(::VectorProperty, OffsetLow, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OffsetMid, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OffsetHigh, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
