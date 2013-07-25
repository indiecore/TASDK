#pragma once
#include "Engine__Actor.h"
#include "TribesGame__TrProj_Grenade.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_MIRVLauncher." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_MIRVLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_MIRVLauncher : public TrProj_Grenade
	{
	public:
		ADD_VAR(::IntProperty, m_nSecondaryExplosions, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_SecondaryProjectile)
		// Here lies the not-yet-implemented method 'GetRandomSpread'
		// Here lies the not-yet-implemented method 'SpawnSecondaryProjectile'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'Bounce'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
