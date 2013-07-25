#pragma once
#include "Engine__InterpTrackInst.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackInstMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstMove : public InterpTrackInst
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat' for the property named 'InitialQuat'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'InitialTM'!
		ADD_STRUCT(::RotatorProperty, ResetRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ResetLocation, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
