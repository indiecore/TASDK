#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNotify_Trails.TrailSample." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNotify_Trails.TrailSample." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrailSample
	{
	public:
		ADD_STRUCT(::VectorProperty, SecondEdgeSample, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ControlPointSample, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FirstEdgeSample, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RelativeTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
