#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.AICommandNodeBase.h"
namespace UnrealScript
{
	class AITree_DMC_Base : public Object
	{
	public:
		void PrintString(ScriptString* InString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.PrintString");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = InString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetWorldTime(class Actor* inActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.GetWorldTime");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = inActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Conv_IntToFloat(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_IntToFloat");
			byte params[8] = { NULL };
			*(int*)&params[0] = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* Conv_FloatToString(float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_FloatToString");
			byte params[16] = { NULL };
			*(float*)&params[0] = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_IntToString(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_IntToString");
			byte params[16] = { NULL };
			*(int*)&params[0] = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_BoolToString(bool InBool)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_BoolToString");
			byte params[16] = { NULL };
			*(bool*)&params[0] = InBool;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_VectorToString(Object::Vector InVec)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_VectorToString");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = InVec;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Conv_RotatorToString(Object::Rotator InRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.Conv_RotatorToString");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = InRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		Object::Vector MakeVector(float X, float Y, float Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.MakeVector");
			byte params[24] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		void BreakVector(Object::Vector InVec, float& X, float& Y, float& Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.BreakVector");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = InVec;
			*(float*)&params[12] = X;
			*(float*)&params[16] = Y;
			*(float*)&params[20] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(float*)&params[12];
			Y = *(float*)&params[16];
			Z = *(float*)&params[20];
		}
		Object::Rotator MakeRot(float Pitch, float Yaw, float Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.MakeRot");
			byte params[24] = { NULL };
			*(float*)&params[0] = Pitch;
			*(float*)&params[4] = Yaw;
			*(float*)&params[8] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		void BreakRot(Object::Rotator InRot, float& Pitch, float& Yaw, float& Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.BreakRot");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = InRot;
			*(float*)&params[12] = Pitch;
			*(float*)&params[16] = Yaw;
			*(float*)&params[20] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Pitch = *(float*)&params[12];
			Yaw = *(float*)&params[16];
			Roll = *(float*)&params[20];
		}
		void CalculateUtilityRating(class AICommandNodeBase* CommandNode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree_DMC_Base.CalculateUtilityRating");
			byte params[4] = { NULL };
			*(class AICommandNodeBase**)&params[0] = CommandNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
