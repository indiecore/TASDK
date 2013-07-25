#pragma once
#include "TribesGame__TrCaHCapturePoint.h"
#include "TribesGame__TrGameObjective.h"
#include "TribesGame__TrStationCollision.h"
#include "Engine__SoundCue.h"
#include "TribesGame__TrPawn.h"
#include "Engine__Actor.h"
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
		ADD_OBJECT(ScriptClass, StationCollisionClass)
		ADD_OBJECT(TrPawn, r_CurrentPawn)
		ADD_OBJECT(TrStationCollision, m_Collision)
		ADD_VAR(::FloatProperty, m_fStationZOffset, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PawnEnteredStation'
		// Here lies the not-yet-implemented method 'PawnLeftStation'
		// Here lies the not-yet-implemented method 'PlayStationEnteredEffects'
		// Here lies the not-yet-implemented method 'PlayStationLeftEffects'
		// Here lies the not-yet-implemented method 'BlocksLineChecksFromSourceActor'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
