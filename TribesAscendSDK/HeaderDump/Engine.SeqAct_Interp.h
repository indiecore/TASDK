#pragma once
#include "Engine.SeqAct_Latent.h"
#include "Engine.InterpGroupInst.h"
#include "Engine.CoverLink.h"
#include "Engine.MatineeActor.h"
#include "Engine.PlayerController.h"
#include "Engine.InterpData.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_Interp : public SeqAct_Latent
	{
	public:
		class CameraCutInfo
		{
		public:
			ADD_STRUCT(float, TimeStamp, 12)
			ADD_STRUCT(Object::Vector, Location, 0)
		};
		class SavedTransform
		{
		public:
			ADD_STRUCT(Object::Rotator, Rotation, 12)
			ADD_STRUCT(Object::Vector, Location, 0)
		};
		ADD_BOOL(bReversePlayback, 380, 0x80)
		ADD_BOOL(bNoResetOnRewind, 380, 0x20)
		ADD_BOOL(bRewindOnPlay, 380, 0x10)
		ADD_BOOL(bIsPlaying, 380, 0x1)
		ADD_BOOL(bPaused, 380, 0x2)
		ADD_STRUCT(float, PlayRate, 368)
		ADD_STRUCT(float, Position, 372)
		ADD_STRUCT(ScriptArray<class InterpGroupInst*>, GroupInst, 400)
		ADD_STRUCT(ScriptArray<class CoverLink*>, LinkedCover, 384)
		ADD_STRUCT(ScriptArray<SeqAct_Interp::CameraCutInfo>, CameraCuts, 424)
		ADD_STRUCT(float, TerminationTime, 436)
		ADD_STRUCT(int, PreferredSplitScreenNum, 420)
		ADD_OBJECT(MatineeActor, ReplicatedActor, 416)
		ADD_OBJECT(ScriptClass, ReplicatedActorClass, 412)
		ADD_OBJECT(InterpData, InterpData, 396)
		ADD_BOOL(bShouldShowGore, 380, 0x4000)
		ADD_BOOL(bIsSkippable, 380, 0x2000)
		ADD_BOOL(bSkipUpdateIfNotVisible, 380, 0x1000)
		ADD_BOOL(bClientSideOnly, 380, 0x800)
		ADD_BOOL(bDisableRadioFilter, 380, 0x400)
		ADD_BOOL(bForceStartPos, 380, 0x200)
		ADD_BOOL(bInterpForPathBuilding, 380, 0x100)
		ADD_BOOL(bRewindIfAlreadyPlaying, 380, 0x40)
		ADD_BOOL(bLooping, 380, 0x8)
		ADD_BOOL(bIsBeingEdited, 380, 0x4)
		ADD_STRUCT(float, ForceStartPosition, 376)
		void AddPlayerToDirectorTracks(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Interp.AddPlayerToDirectorTracks");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPosition(float NewPosition, bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Interp.SetPosition");
			byte params[8] = { NULL };
			*(float*)&params[0] = NewPosition;
			*(bool*)&params[4] = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Stop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Interp.Stop");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Interp.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Interp.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
