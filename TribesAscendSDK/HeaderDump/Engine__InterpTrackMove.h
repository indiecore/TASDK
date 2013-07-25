#pragma once
#include "Engine__InterpTrack.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.InterpTrackMove.InterpLookupTrack' for the property named 'LookupTrack'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector' for the property named 'EulerTrack'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector' for the property named 'PosTrack'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
