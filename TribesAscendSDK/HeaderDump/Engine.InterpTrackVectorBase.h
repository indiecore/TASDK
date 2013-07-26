#pragma once
#include "Engine.InterpTrack.h"
#include "Core.Object.InterpCurveVector.h"
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
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector>, VectorTrack, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
