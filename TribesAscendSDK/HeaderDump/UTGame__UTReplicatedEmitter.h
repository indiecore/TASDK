#pragma once
#include "UTGame__UTEmitter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTReplicatedEmitter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTReplicatedEmitter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTReplicatedEmitter : public UTEmitter
	{
	public:
		ADD_VAR(::FloatProperty, ServerLifeSpan, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, EmitterTemplate)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
