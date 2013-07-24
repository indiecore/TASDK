#pragma once
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
	};
}
#undef ADD_VAR
