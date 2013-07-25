#pragma once
#include "Engine__KActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKKActorBreakable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKKActorBreakable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKKActorBreakable : public KActor
	{
	public:
		ADD_OBJECT(Controller, InstigatorController)
		ADD_OBJECT(ParticleSystem, BrokenTemplate)
		ADD_VAR(::IntProperty, DOEResetThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EncroachDamage_Self, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EncroachDamage_Other, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Health, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBroken, 0x20)
		ADD_VAR(::BoolProperty, bBreakWhenCausingDamage, 0x10)
		ADD_VAR(::BoolProperty, bTakeDamageOnEncroachment, 0x8)
		ADD_VAR(::BoolProperty, bResetDOEWhenAsleep, 0x4)
		ADD_VAR(::BoolProperty, bDamageOnEncroachment, 0x2)
		ADD_VAR(::BoolProperty, bHasHealth, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
