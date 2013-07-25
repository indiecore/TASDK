#pragma once
#include "Engine.InterpTrack.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackVectorBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackVectorBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackVectorBase : public InterpTrack
	{
	public:
		ADD_VAR(::FloatProperty, CurveTension, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector' for the property named 'VectorTrack'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
