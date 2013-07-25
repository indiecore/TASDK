#pragma once
#include "UTGame__UTPawn.h"
#include "UTGame__UTWeaponAttachment.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTBeamWeaponAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTBeamWeaponAttachment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTBeamWeaponAttachment : public UTWeaponAttachment
	{
	public:
		ADD_VAR(::NameProperty, EndPointParamName, 0xFFFFFFFF)
		ADD_OBJECT(UTPawn, PawnOwner)
		ADD_VAR(::NameProperty, BeamSockets, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, BeamTemplate)
		// Here lies the not-yet-implemented method 'AddBeamEmitter'
		// Here lies the not-yet-implemented method 'HideEmitter'
		// Here lies the not-yet-implemented method 'UpdateBeam'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
