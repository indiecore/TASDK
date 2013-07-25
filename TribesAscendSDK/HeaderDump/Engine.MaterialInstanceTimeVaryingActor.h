#pragma once
#include "Engine.Actor.h"
#include "Engine.MaterialInstanceTimeVarying.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialInstanceTimeVaryingActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialInstanceTimeVaryingActor : public Actor
	{
	public:
		ADD_OBJECT(MaterialInstanceTimeVarying, MatInst)
	};
}
#undef ADD_OBJECT
