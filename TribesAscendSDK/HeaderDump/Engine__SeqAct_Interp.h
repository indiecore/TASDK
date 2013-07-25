#pragma once
#include "Engine__SeqAct_Latent.h"
#include "Engine__MatineeActor.h"
#include "Engine__InterpData.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Interp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_Interp." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_Interp : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bReversePlayback, 0x80)
		ADD_VAR(::BoolProperty, bNoResetOnRewind, 0x20)
		ADD_VAR(::BoolProperty, bRewindOnPlay, 0x10)
		ADD_VAR(::BoolProperty, bIsPlaying, 0x1)
		ADD_VAR(::BoolProperty, bPaused, 0x2)
		ADD_VAR(::FloatProperty, PlayRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Position, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TerminationTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PreferredSplitScreenNum, 0xFFFFFFFF)
		ADD_OBJECT(MatineeActor, ReplicatedActor)
		ADD_OBJECT(ScriptClass, ReplicatedActorClass)
		ADD_OBJECT(InterpData, InterpData)
		ADD_VAR(::BoolProperty, bShouldShowGore, 0x4000)
		ADD_VAR(::BoolProperty, bIsSkippable, 0x2000)
		ADD_VAR(::BoolProperty, bSkipUpdateIfNotVisible, 0x1000)
		ADD_VAR(::BoolProperty, bClientSideOnly, 0x800)
		ADD_VAR(::BoolProperty, bDisableRadioFilter, 0x400)
		ADD_VAR(::BoolProperty, bForceStartPos, 0x200)
		ADD_VAR(::BoolProperty, bInterpForPathBuilding, 0x100)
		ADD_VAR(::BoolProperty, bRewindIfAlreadyPlaying, 0x40)
		ADD_VAR(::BoolProperty, bLooping, 0x8)
		ADD_VAR(::BoolProperty, bIsBeingEdited, 0x4)
		ADD_VAR(::FloatProperty, ForceStartPosition, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AddPlayerToDirectorTracks'
		// Here lies the not-yet-implemented method 'SetPosition'
		// Here lies the not-yet-implemented method 'Stop'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
