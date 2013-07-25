#pragma once
#include "Engine__Pawn.h"
#include "Engine__SavedMove.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSavedMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSavedMove : public SavedMove
	{
	public:
		ADD_VAR(::ByteProperty, m_CurrentDecelerationFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bBlink, 0x8)
		ADD_VAR(::BoolProperty, m_bJumpJet, 0x4)
		ADD_VAR(::BoolProperty, m_bPressingJetpack, 0x2)
		ADD_VAR(::BoolProperty, m_bAirSpeedBoundToGroundSpeed, 0x1)
		// Here lies the not-yet-implemented method 'Clear'
		// Here lies the not-yet-implemented method 'PostUpdate'
		// Here lies the not-yet-implemented method 'CanCombineWith'
		// Here lies the not-yet-implemented method 'SetMoveFor'
		// Here lies the not-yet-implemented method 'CompressedFlags'
		// Here lies the not-yet-implemented method 'SetFlags'
		// Here lies the not-yet-implemented method 'GetDebugString'
	};
}
#undef ADD_VAR
