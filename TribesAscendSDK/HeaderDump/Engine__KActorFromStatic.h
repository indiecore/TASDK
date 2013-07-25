#pragma once
#include "Engine__Actor.h"
#include "Engine__KActor.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KActorFromStatic." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.KActorFromStatic." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class KActorFromStatic : public KActor
	{
	public:
		ADD_VAR(::FloatProperty, MaxImpulseSpeed, 0xFFFFFFFF)
		ADD_OBJECT(Actor, MyStaticMeshActor)
		// Here lies the not-yet-implemented method 'MakeDynamic'
		// Here lies the not-yet-implemented method 'DisablePrecomputedLighting'
		// Here lies the not-yet-implemented method 'OnSleepRBPhysics'
		// Here lies the not-yet-implemented method 'OnWakeRBPhysics'
		// Here lies the not-yet-implemented method 'BecomeStatic'
		// Here lies the not-yet-implemented method 'MakeStatic'
		// Here lies the not-yet-implemented method 'ApplyImpulse'
		// Here lies the not-yet-implemented method 'ReceiveImpulse'
		// Here lies the not-yet-implemented method 'Bump'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
