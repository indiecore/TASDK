#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrStation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrStation : public TrGameObjective
	{
	public:
		ADD_OBJECT(TrCaHCapturePoint, m_OwningCaHCapturePoint)
		ADD_OBJECT(SoundCue, m_StationLeftSoundCue)
		ADD_OBJECT(SoundCue, m_StationEnteredSoundCue)
		ADD_OBJECT(TrPawn, r_CurrentPawn)
		ADD_OBJECT(TrStationCollision, m_Collision)
		ADD_VAR(::FloatProperty, m_fStationZOffset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
