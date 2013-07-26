#pragma once
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PlayerController.InputMatchRequest." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PlayerController.InputMatchRequest." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InputMatchRequest
	{
	public:
		ADD_OBJECT(Actor, MatchActor)
		ADD_VAR(::NameProperty, MatchFuncName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FailedFuncName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RequestName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MatchIdx, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastMatchTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
