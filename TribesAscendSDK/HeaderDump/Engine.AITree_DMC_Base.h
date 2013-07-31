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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10001);
			byte params[12] = { NULL };
			*(ScriptString**)params = InString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetWorldTime(class Actor* inActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10003);
			byte params[8] = { NULL };
			*(class Actor**)params = inActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float Conv_IntToFloat(int InInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10006);
			byte params[8] = { NULL };
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* Conv_FloatToString(float InFloat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10009);
			byte params[16] = { NULL };
			*(float*)params = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_IntToString(int InInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10012);
			byte params[16] = { NULL };
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_BoolToString(bool InBool)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10015);
			byte params[16] = { NULL };
			*(bool*)params = InBool;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_VectorToString(Vector InVec)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10018);
			byte params[24] = { NULL };
			*(Vector*)params = InVec;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Conv_RotatorToString(Rotator InRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10021);
			byte params[24] = { NULL };
			*(Rotator*)params = InRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		Vector MakeVector(float X, float Y, float Z)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10024);
			byte params[24] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void BreakVector(Vector InVec, float& X, float& Y, float& Z)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10030);
			byte params[24] = { NULL };
			*(Vector*)params = InVec;
			*(float*)&params[12] = X;
			*(float*)&params[16] = Y;
			*(float*)&params[20] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(float*)&params[12];
			Y = *(float*)&params[16];
			Z = *(float*)&params[20];
		}
		Rotator MakeRot(float Pitch, float Yaw, float Roll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10035);
			byte params[24] = { NULL };
			*(float*)params = Pitch;
			*(float*)&params[4] = Yaw;
			*(float*)&params[8] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		void BreakRot(Rotator InRot, float& Pitch, float& Yaw, float& Roll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10041);
			byte params[24] = { NULL };
			*(Rotator*)params = InRot;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10046);
			byte params[4] = { NULL };
			*(class AICommandNodeBase**)params = CommandNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
