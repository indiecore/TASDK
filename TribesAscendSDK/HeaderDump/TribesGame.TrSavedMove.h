#pragma once
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "Engine.SavedMove.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class TrSavedMove : public SavedMove
	{
	public:
		ADD_STRUCT(TrPawn::WalkingDeceleration, m_CurrentDecelerationFactor, 236)
		ADD_BOOL(m_bBlink, 232, 0x8)
		ADD_BOOL(m_bJumpJet, 232, 0x4)
		ADD_BOOL(m_bPressingJetpack, 232, 0x2)
		ADD_BOOL(m_bAirSpeedBoundToGroundSpeed, 232, 0x1)
		void Clear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.Clear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostUpdate(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.PostUpdate");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanCombineWith(class SavedMove* NewMove, class Pawn* inPawn, float MaxDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.CanCombineWith");
			byte params[16] = { NULL };
			*(class SavedMove**)&params[0] = NewMove;
			*(class Pawn**)&params[4] = inPawn;
			*(float*)&params[8] = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetMoveFor(class PlayerController* P, float DeltaTime, Object::Vector newAccel, Actor::EDoubleClickDir InDoubleClick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.SetMoveFor");
			byte params[21] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(float*)&params[4] = DeltaTime;
			*(Object::Vector*)&params[8] = newAccel;
			*(Actor::EDoubleClickDir*)&params[20] = InDoubleClick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte CompressedFlags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.CompressedFlags");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		Actor::EDoubleClickDir SetFlags(byte Flags, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.SetFlags");
			byte params[6] = { NULL };
			params[0] = Flags;
			*(class PlayerController**)&params[4] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::EDoubleClickDir*)&params[8];
		}
		ScriptString* GetDebugString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.GetDebugString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
