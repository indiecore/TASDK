#pragma once
#include "GameFramework.GamePawn.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameSpecialMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameSpecialMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameSpecialMove." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameSpecialMove : public Object
	{
	public:
		ADD_STRUCT(::RotatorProperty, PreciseRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PreciseRotationInterpolationTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PreciseDestRelOffset, 0xFFFFFFFF)
		ADD_OBJECT(Actor, PreciseDestBase)
		ADD_STRUCT(::VectorProperty, PreciseDestination, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForcePrecisePosition, 0x20)
		ADD_VAR(::BoolProperty, bReachedPreciseRotation, 0x10)
		ADD_VAR(::BoolProperty, bReachPreciseRotation, 0x8)
		ADD_VAR(::BoolProperty, bReachedPreciseDestination, 0x4)
		ADD_VAR(::BoolProperty, bReachPreciseDestination, 0x2)
		ADD_VAR(::BoolProperty, bLastCanDoSpecialMove, 0x1)
		ADD_VAR(::FloatProperty, LastCanDoSpecialMoveTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Handle, 0xFFFFFFFF)
		ADD_OBJECT(GamePawn, PawnOwner)
		void InitSpecialMove(class GamePawn* inPawn, ScriptName InHandle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.InitSpecialMove");
			byte* params = (byte*)malloc(12);
			*(class GamePawn**)params = inPawn;
			*(ScriptName*)(params + 4) = InHandle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitSpecialMoveFlags(int& out_Flags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.InitSpecialMoveFlags");
			byte* params = (byte*)malloc(4);
			*(int*)params = out_Flags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Flags = *(int*)params;
			free(params);
		}
		void ExtractSpecialMoveFlags(int Flags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ExtractSpecialMoveFlags");
			byte* params = (byte*)malloc(4);
			*(int*)params = Flags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanChainMove(ScriptName NextMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanChainMove");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NextMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool CanOverrideMoveWith(ScriptName NewMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanOverrideMoveWith");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool CanOverrideSpecialMove(ScriptName InMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanOverrideSpecialMove");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool CanDoSpecialMove(bool bForceCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanDoSpecialMove");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForceCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool InternalCanDoSpecialMove()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.InternalCanDoSpecialMove");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SpecialMoveStarted(bool bForced, ScriptName PrevMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SpecialMoveStarted");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bForced;
			*(ScriptName*)(params + 4) = PrevMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpecialMoveEnded(ScriptName PrevMove, ScriptName NextMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SpecialMoveEnded");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = PrevMove;
			*(ScriptName*)(params + 8) = NextMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpecialMoveFlagsUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SpecialMoveFlagsUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldReplicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ShouldReplicate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetReachPreciseDestination(Vector DestinationToReach, bool bCancel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SetReachPreciseDestination");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = DestinationToReach;
			*(bool*)(params + 12) = bCancel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFacePreciseRotation(Rotator RotationToFace, float InterpolationTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SetFacePreciseRotation");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = RotationToFace;
			*(float*)(params + 12) = InterpolationTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReachedPrecisePosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ReachedPrecisePosition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetFacePreciseRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ResetFacePreciseRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MessageEvent(ScriptName EventName, class Object* Sender)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.MessageEvent");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = EventName;
			*(class Object**)(params + 8) = Sender;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void ForcePawnRotation(class Pawn* P, Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ForcePawnRotation");
			byte* params = (byte*)malloc(16);
			*(class Pawn**)params = P;
			*(Rotator*)(params + 4) = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector WorldToRelativeOffset(Rotator InRotation, Vector WorldSpaceOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.WorldToRelativeOffset");
			byte* params = (byte*)malloc(36);
			*(Rotator*)params = InRotation;
			*(Vector*)(params + 12) = WorldSpaceOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		Vector RelativeToWorldOffset(Rotator InRotation, Vector RelativeSpaceOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.RelativeToWorldOffset");
			byte* params = (byte*)malloc(36);
			*(Rotator*)params = InRotation;
			*(Vector*)(params + 12) = RelativeSpaceOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
