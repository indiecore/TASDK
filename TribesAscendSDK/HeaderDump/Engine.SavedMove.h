#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SavedMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SavedMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SavedMove." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SavedMove : public Object
	{
	public:
		ADD_VAR(::FloatProperty, TimeStamp, 0xFFFFFFFF)
		ADD_OBJECT(SavedMove, NextMove)
		ADD_STRUCT(::VectorProperty, Acceleration, 0xFFFFFFFF)
		ADD_OBJECT(Actor, EndBase)
		ADD_STRUCT(::VectorProperty, SavedRelativeLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SavedLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SavedVelocity, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceRMVelocity, 0x20)
		ADD_VAR(::FloatProperty, Delta, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DoubleClickMove, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartVelocity, 0xFFFFFFFF)
		ADD_OBJECT(Actor, StartBase)
		ADD_STRUCT(::VectorProperty, StartFloor, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RootMotionInterpCurveLastValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RootMotionInterpCurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccelDotThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CustomTimeDilation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RMVelocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartRelativeLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartLocation, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RootMotionMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SavedPhysics, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRootMotionFromInterpCurve, 0x80)
		ADD_VAR(::BoolProperty, bForceMaxAccel, 0x40)
		ADD_VAR(::BoolProperty, bPreciseDestination, 0x10)
		ADD_VAR(::BoolProperty, bDoubleJump, 0x8)
		ADD_VAR(::BoolProperty, bPressedJump, 0x4)
		ADD_VAR(::BoolProperty, bDuck, 0x2)
		ADD_VAR(::BoolProperty, bRun, 0x1)
		byte SetFlags(byte Flags, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.SetFlags");
			byte* params = (byte*)malloc(6);
			*params = Flags;
			*(class PlayerController**)(params + 4) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		byte CompressedFlags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.CompressedFlags");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool IsImportantMove(Vector CompareAccel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.IsImportantMove");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = CompareAccel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CanCombineWith(class SavedMove* NewMove, class Pawn* inPawn, float MaxDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.CanCombineWith");
			byte* params = (byte*)malloc(16);
			*(class SavedMove**)params = NewMove;
			*(class Pawn**)(params + 4) = inPawn;
			*(float*)(params + 8) = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector GetStartLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.GetStartLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void Clear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.Clear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostUpdate(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.PostUpdate");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetInitialPosition(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.SetInitialPosition");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMoveFor(class PlayerController* P, float DeltaTime, Vector newAccel, byte InDoubleClick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.SetMoveFor");
			byte* params = (byte*)malloc(21);
			*(class PlayerController**)params = P;
			*(float*)(params + 4) = DeltaTime;
			*(Vector*)(params + 8) = newAccel;
			*(params + 20) = InDoubleClick;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PrepMoveFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.PrepMoveFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetMoveFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.ResetMoveFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetDebugString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.GetDebugString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
