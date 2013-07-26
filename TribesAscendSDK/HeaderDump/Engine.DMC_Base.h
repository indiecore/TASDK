#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#include "Engine.Actor.TraceHitInfo.h"
namespace UnrealScript
{
	class DMC_Base : public Actor
	{
	public:
		void PrintString(ScriptArray<wchar_t> InString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.PrintString");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = InString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetWorldTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.GetWorldTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float Conv_IntToFloat(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_IntToFloat");
			byte* params = (byte*)malloc(8);
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_FloatToString(float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_FloatToString");
			byte* params = (byte*)malloc(16);
			*(float*)params = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_IntToString(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_IntToString");
			byte* params = (byte*)malloc(16);
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_BoolToString(bool InBool)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_BoolToString");
			byte* params = (byte*)malloc(16);
			*(bool*)params = InBool;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_VectorToString(Vector InVec)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_VectorToString");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InVec;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_RotatorToString(Rotator InRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_RotatorToString");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = InRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector MakeVector(float X, float Y, float Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.MakeVector");
			byte* params = (byte*)malloc(24);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			*(float*)(params + 8) = Z;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void BreakVector(Vector InVec, float& X, float& Y, float& Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.BreakVector");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InVec;
			*(float*)(params + 12) = X;
			*(float*)(params + 16) = Y;
			*(float*)(params + 20) = Z;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			X = *(float*)(params + 12);
			Y = *(float*)(params + 16);
			Z = *(float*)(params + 20);
			free(params);
		}
		Rotator MakeRot(float Pitch, float Yaw, float Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.MakeRot");
			byte* params = (byte*)malloc(24);
			*(float*)params = Pitch;
			*(float*)(params + 4) = Yaw;
			*(float*)(params + 8) = Roll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		void BreakRot(Rotator InRot, float& Pitch, float& Yaw, float& Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.BreakRot");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = InRot;
			*(float*)(params + 12) = Pitch;
			*(float*)(params + 16) = Yaw;
			*(float*)(params + 20) = Roll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Pitch = *(float*)(params + 12);
			Yaw = *(float*)(params + 16);
			Roll = *(float*)(params + 20);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AddComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Template)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.AddComponent");
			byte* params = (byte*)malloc(8);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Template;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void DMCCreate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.DMCCreate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DMCTakeDamage(int DamageAmount, Vector HitLocation, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.DMCTakeDamage");
			byte* params = (byte*)malloc(28);
			*(int*)params = DamageAmount;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
