#pragma once
#include "Engine.InterpTrack.h"
#include "Engine.InterpTrackMove.InterpLookupTrack.h"
#include "Core.Object.InterpCurveVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackMove : public InterpTrack
	{
	public:
		ADD_VAR(::ByteProperty, RotMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MoveFrame, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHide3DTrack, 0x20)
		ADD_VAR(::BoolProperty, bShowRotationOnCurveEd, 0x10)
		ADD_VAR(::BoolProperty, bShowTranslationOnCurveEd, 0x8)
		ADD_VAR(::BoolProperty, bDisableMovement, 0x4)
		ADD_VAR(::BoolProperty, bShowArrowAtKeys, 0x2)
		ADD_VAR(::BoolProperty, bUseQuatInterpolation, 0x1)
		ADD_VAR(::FloatProperty, AngCurveTension, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinCurveTension, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LookAtGroupName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpLookupTrack>, LookupTrack, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector>, EulerTrack, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector>, PosTrack, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
