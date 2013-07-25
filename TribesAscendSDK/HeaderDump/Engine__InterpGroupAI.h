#pragma once
#include "Engine__InterpGroup.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpGroupAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpGroupAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpGroupAI : public InterpGroup
	{
	public:
		ADD_VAR(::BoolProperty, bNoEncroachmentCheck, 0x2)
		ADD_VAR(::BoolProperty, SnapToRootBoneLocationWhenFinished, 0x1)
		ADD_OBJECT(Actor, StageMarkActor)
		ADD_OBJECT(Pawn, PreviewPawn)
		ADD_VAR(::NameProperty, StageMarkGroup, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, PreviewPawnClass)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
