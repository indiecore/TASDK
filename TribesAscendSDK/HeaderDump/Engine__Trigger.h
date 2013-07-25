#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Trigger." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Trigger : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bRecentlyTriggered, 0x1)
		ADD_VAR(::FloatProperty, AITriggerDelay, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
