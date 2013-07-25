#pragma once
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#include "Engine__SeqAct_Interp.h"
#include "Engine__InterpGroupInstAI.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MatineeActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MatineeActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MatineeActor : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, ClientSidePositionErrorTolerance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AIGroupInitStage, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, AIGroupPawns)
		ADD_VAR(::NameProperty, AIGroupNames, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Position, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PlayRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, AllAIGroupsInitialized, 0x8)
		ADD_VAR(::BoolProperty, bPaused, 0x4)
		ADD_VAR(::BoolProperty, bReversePlayback, 0x2)
		ADD_VAR(::BoolProperty, bIsPlaying, 0x1)
		ADD_OBJECT(SeqAct_Interp, InterpAction)
		// Here lies the not-yet-implemented method 'AddAIGroupActor'
		// Here lies the not-yet-implemented method 'Update'
		// Here lies the not-yet-implemented method 'CheckPriorityRefresh'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
