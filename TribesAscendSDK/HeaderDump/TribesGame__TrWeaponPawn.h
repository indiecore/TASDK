#pragma once
#include "UTGame__UTWeaponPawn.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrWeaponPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrWeaponPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrWeaponPawn : public UTWeaponPawn
	{
	public:
		ADD_VAR(::FloatProperty, m_fCurrentAccuracy, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nFlashReload, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, r_scFiringLoop)
		ADD_VAR(::BoolProperty, r_bFiringLoopSound, 0x1)
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PlayReload'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'ClientPlayLoopSound'
		// Here lies the not-yet-implemented method 'PlayLoopingSound'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
