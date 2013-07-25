#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Light." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Light : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'OnToggle'
	};
}
#undef ADD_VAR
