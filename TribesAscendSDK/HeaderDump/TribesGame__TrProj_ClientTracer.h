#pragma once
#include "TribesGame__TrProjectile.h"
#include "Engine__SoundCue.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_ClientTracer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_ClientTracer : public TrProjectile
	{
	public:
		ADD_OBJECT(ScriptClass, m_InheritedClass)
		// Here lies the not-yet-implemented method 'InitProjectile'
		// Here lies the not-yet-implemented method 'GetExplosionSound'
		// Here lies the not-yet-implemented method 'ProcessTouch'
	};
}
#undef ADD_OBJECT
