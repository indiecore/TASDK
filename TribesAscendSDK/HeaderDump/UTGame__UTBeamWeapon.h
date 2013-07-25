#pragma once
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
#include "UTGame__UTWeapon.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTBeamWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTBeamWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTBeamWeapon : public UTWeapon
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, BeamWeaponFireWaveForm)
		ADD_VAR(::NameProperty, BeamPostFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamPreFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EndPointParamName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamSockets, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, BeamTemplate)
		// Here lies the not-yet-implemented method 'AddBeamEmitter'
		// Here lies the not-yet-implemented method 'KillBeamEmitter'
		// Here lies the not-yet-implemented method 'SetBeamEmitterHidden'
		// Here lies the not-yet-implemented method 'UpdateBeamEmitter'
		// Here lies the not-yet-implemented method 'ProcessBeamHit'
		// Here lies the not-yet-implemented method 'UpdateBeam'
		// Here lies the not-yet-implemented method 'DisplayDebug'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
