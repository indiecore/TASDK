#pragma once
#include "Engine__InterpTrack.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackLinearColorBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackLinearColorBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackLinearColorBase : public InterpTrack
	{
	public:
		ADD_VAR(::FloatProperty, CurveTension, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveLinearColor' for the property named 'LinearColorTrack'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
