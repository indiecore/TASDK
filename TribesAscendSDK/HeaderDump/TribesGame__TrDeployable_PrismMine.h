#pragma once
#include "Engine__SoundCue.h"
#include "TribesGame__TrDeployable.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Pawn.h"
#include "TribesGame__TrTripActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable_PrismMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_PrismMine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_PrismMine : public TrDeployable
	{
	public:
		ADD_OBJECT(SoundCue, m_HitSound)
		ADD_OBJECT(SoundCue, m_DeactivateSound)
		ADD_OBJECT(SoundCue, m_ActivateSound)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate)
		ADD_VAR(::IntProperty, m_DamageAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSleepTimeAfterHit, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_DamageType)
		ADD_VAR(::NameProperty, m_nSocketTraceName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPrismRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_TrTripNotifier'!
		// Here lies the not-yet-implemented method 'CreateTripActor'
		// Here lies the not-yet-implemented method 'DestroyTripActor'
		// Here lies the not-yet-implemented method 'AddTripActor'
		// Here lies the not-yet-implemented method 'RemoveTripActor'
		// Here lies the not-yet-implemented method 'TripActivated'
		// Here lies the not-yet-implemented method 'GetParticleSystemName'
		// Here lies the not-yet-implemented method 'GetTripSocketPosition'
		// Here lies the not-yet-implemented method 'OnTripAwake'
		// Here lies the not-yet-implemented method 'OnTripSleep'
		// Here lies the not-yet-implemented method 'DeployComplete'
		// Here lies the not-yet-implemented method 'NoConnectionExists'
		// Here lies the not-yet-implemented method 'OnPowerStatusChanged'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
