#pragma once
#include "Engine.Actor.h"
#include "GameFramework.GamePawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameTypes.SpecialMoveStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameTypes.SpecialMoveStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SpecialMoveStruct
	{
	public:
		ADD_VAR(::NameProperty, SpecialMoveName, 0xFFFFFFFF)
		ADD_OBJECT(GamePawn, InteractionPawn)
		ADD_OBJECT(Actor, InteractionActor)
		ADD_VAR(::IntProperty, Flags, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
