#pragma once
#include "Core__Object.h"
#include "Engine__Actor.h"
#include "Engine__InterpGroup.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpGroupInst." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpGroupInst : public Object
	{
	public:
		ADD_OBJECT(Actor, GroupActor)
		ADD_OBJECT(InterpGroup, Group)
	};
}
#undef ADD_OBJECT
