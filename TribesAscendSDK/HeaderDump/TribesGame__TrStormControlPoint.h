#pragma once
#include "TribesGame__TrGameObjective.h"
#include "TribesGame__TrPawn.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStormControlPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrStormControlPoint : public TrGameObjective
	{
	public:
		ADD_VAR(::StrProperty, m_sControlPointName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLaunchTimeDescriptionPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fControlDescriptionPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMissileFlightTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMissileLaunchTrackerSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMissileLaunchTracker, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentTransitionAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTransitionSpeed, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_CurrentControlPointState, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'OnPawnTouched'
		// Here lies the not-yet-implemented method 'GetControlPointState'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'FireMissile'
		// Here lies the not-yet-implemented method 'BeginTransition'
		// Here lies the not-yet-implemented method 'SetControlPointState'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'GetScreenName'
	};
}
#undef ADD_VAR
