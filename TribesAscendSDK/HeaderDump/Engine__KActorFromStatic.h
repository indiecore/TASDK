#pragma once
#include "Engine__KActor.h"
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
