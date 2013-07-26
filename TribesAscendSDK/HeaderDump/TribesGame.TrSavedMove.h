#pragma once
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
#include "Engine.SavedMove.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSavedMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSavedMove : public SavedMove
	{
	public:
		ADD_VAR(::ByteProperty, m_CurrentDecelerationFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bBlink, 0x8)
		ADD_VAR(::BoolProperty, m_bJumpJet, 0x4)
		ADD_VAR(::BoolProperty, m_bPressingJetpack, 0x2)
		ADD_VAR(::BoolProperty, m_bAirSpeedBoundToGroundSpeed, 0x1)
		void Clear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.Clear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostUpdate(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.PostUpdate");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanCombineWith(class SavedMove* NewMove, class Pawn* inPawn, float MaxDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.CanCombineWith");
			byte* params = (byte*)malloc(16);
			*(class SavedMove**)params = NewMove;
			*(class Pawn**)(params + 4) = inPawn;
			*(float*)(params + 8) = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetMoveFor(class PlayerController* P, float DeltaTime, Vector newAccel, byte InDoubleClick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.SetMoveFor");
			byte* params = (byte*)malloc(21);
			*(class PlayerController**)params = P;
			*(float*)(params + 4) = DeltaTime;
			*(Vector*)(params + 8) = newAccel;
			*(params + 20) = InDoubleClick;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte CompressedFlags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.CompressedFlags");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		byte SetFlags(byte Flags, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.SetFlags");
			byte* params = (byte*)malloc(6);
			*params = Flags;
			*(class PlayerController**)(params + 4) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetDebugString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSavedMove.GetDebugString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
