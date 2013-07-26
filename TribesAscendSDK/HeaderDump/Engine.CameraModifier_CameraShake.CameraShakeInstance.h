#pragma once
#include "Core.Object.Matrix.h"
#include "Engine.CameraAnimInst.h"
#include "Engine.CameraShake.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CameraModifier_CameraShake.CameraShakeInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CameraModifier_CameraShake.CameraShakeInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty CameraModifier_CameraShake.CameraShakeInstance." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CameraShakeInstance
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, UserPlaySpaceMatrix, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PlaySpace, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnimInst, AnimInst)
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOVSinOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RotSinOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LocSinOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBlendingOut, 0x1)
		ADD_VAR(::FloatProperty, CurrentBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBlendingIn, 0x1)
		ADD_VAR(::FloatProperty, OscillatorTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SourceShakeName, 0xFFFFFFFF)
		ADD_OBJECT(CameraShake, SourceShake)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
