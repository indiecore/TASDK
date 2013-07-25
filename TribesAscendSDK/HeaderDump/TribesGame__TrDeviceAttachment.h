#pragma once
#include "Engine__SoundCue.h"
#include "UTGame__UTPawn.h"
#include "UTGame__UTWeaponAttachment.h"
#include "Engine__Actor.h"
#include "TribesGame__TrProj_Tracer.h"
#include "Engine__ParticleSystem.h"
#include "TribesGame__TrPawn.h"
#include "Engine__Weapon.h"
#include "Engine__PhysicalMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeviceAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeviceAttachment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeviceAttachment : public UTWeaponAttachment
	{
	public:
		ADD_VAR(::NameProperty, m_nmRidingAsPassengerFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_TracerType, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate)
		ADD_VAR(::BoolProperty, m_bScaleFireAnimRate, 0x4)
		ADD_VAR(::BoolProperty, m_bSpawnTracerBeams, 0x2)
		ADD_VAR(::BoolProperty, m_bSpawnTracers, 0x1)
		ADD_VAR(::NameProperty, m_nmHeavyAimProfileName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_nmLightMedAimProfileName, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AttachTo'
		// Here lies the not-yet-implemented method 'InitAnims'
		// Here lies the not-yet-implemented method 'DetachFrom'
		// Here lies the not-yet-implemented method 'SetPuttingDownWeapon'
		// Here lies the not-yet-implemented method 'ShouldFireTracer'
		// Here lies the not-yet-implemented method 'ShouldFireTracerBeam'
		// Here lies the not-yet-implemented method 'ThirdPersonFireEffects'
		// Here lies the not-yet-implemented method 'StopThirdPersonFireEffects'
		// Here lies the not-yet-implemented method 'FirstPersonFireEffects'
		// Here lies the not-yet-implemented method 'SpawnTracerBeam'
		// Here lies the not-yet-implemented method 'SpawnTracerEffect'
		// Here lies the not-yet-implemented method 'GetTracer'
		// Here lies the not-yet-implemented method 'PlayReload'
		// Here lies the not-yet-implemented method 'PlayImpactEffects'
		// Here lies the not-yet-implemented method 'PlayImpactSound'
		// Here lies the not-yet-implemented method 'GetImpactEffect'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
