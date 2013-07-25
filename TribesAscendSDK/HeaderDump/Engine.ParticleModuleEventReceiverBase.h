#pragma once
#include "Engine.ParticleModuleEventBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleEventReceiverBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleEventReceiverBase : public ParticleModuleEventBase
	{
	public:
		ADD_VAR(::NameProperty, EventName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EventGeneratorType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
