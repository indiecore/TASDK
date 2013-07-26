#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#include "Engine.AICommandNodeBase.h"
namespace UnrealScript
{
	class AITree_DMC_Base : public Object
	{
	public:
		void PrintString(ScriptArray<wchar_t> InString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.PrintString");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = InString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetWorldTime(class Actor* inActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.GetWorldTime");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = inActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float Conv_IntToFloat(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_IntToFloat");
			byte* params = (byte*)malloc(8);
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_FloatToString(float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_FloatToString");
			byte* params = (byte*)malloc(16);
			*(float*)params = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_IntToString(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_IntToString");
			byte* params = (byte*)malloc(16);
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_BoolToString(bool InBool)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_BoolToString");
			byte* params = (byte*)malloc(16);
			*(bool*)params = InBool;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_VectorToString(Vector InVec)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_VectorToString");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InVec;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> Conv_RotatorToString(Rotator InRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_RotatorToString");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = InRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector MakeVector(float X, float Y, float Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.MakeVector");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.BreakVector");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.MakeRot");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.BreakRot");
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
		void CalculateUtilityRating(class AICommandNodeBase* CommandNode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.CalculateUtilityRating");
			byte* params = (byte*)malloc(4);
			*(class AICommandNodeBase**)params = CommandNode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
