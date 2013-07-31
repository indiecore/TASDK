#pragma once
#include "Engine.InterpTrackFloatBase.h"
#include "Engine.InterpTrackMove.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackMoveAxis : public InterpTrackFloatBase
	{
	public:
		enum EInterpMoveAxis : byte
		{
			AXIS_TranslationX = 0,
			AXIS_TranslationY = 1,
			AXIS_TranslationZ = 2,
			AXIS_RotationX = 3,
			AXIS_RotationY = 4,
			AXIS_RotationZ = 5,
			AXIS_MAX = 6,
		};
		ADD_STRUCT(InterpTrackMove::InterpLookupTrack, LookupTrack, 152)
		ADD_STRUCT(InterpTrackMoveAxis::EInterpMoveAxis, MoveAxis, 148)
	};
}
#undef ADD_STRUCT
