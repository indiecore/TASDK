#pragma once
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Pawn.LastHitInfoStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Pawn.LastHitInfoStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LastHitInfoStruct
	{
	public:
		ADD_OBJECT(ScriptClass, Type)
		ADD_OBJECT(Actor, Causer)
		ADD_VAR(::FloatProperty, Distance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Amount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDirectHit, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
