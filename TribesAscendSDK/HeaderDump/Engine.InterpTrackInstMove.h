#pragma once
#include "Core.Object.Quat.h"
#include "Engine.InterpTrackInst.h"
#include "Core.Object.Matrix.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
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
		ADD_STRUCT(::NonArithmeticProperty<Quat>, InitialQuat, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, InitialTM, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, ResetRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ResetLocation, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
