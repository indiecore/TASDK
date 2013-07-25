#pragma once
#include "Engine__NavMeshPathConstraint.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavMeshPath_SameCoverLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPath_SameCoverLink : public NavMeshPathConstraint
	{
	public:
		ADD_OBJECT(CoverLink, TestLink)
	};
}
#undef ADD_OBJECT
