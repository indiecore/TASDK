#pragma once
#include "Engine.Actor.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialInstanceActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialInstanceActor : public Actor
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, MatInst)
	};
}
#undef ADD_OBJECT
