#pragma once
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DMC_Base : public Actor
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, CreatedComponents, 476)
		void PrintString(ScriptString* InString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14529);
			byte params[12] = { NULL };
			*(ScriptString**)params = InString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetWorldTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14531);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float Conv_IntToFloat(int InInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14533);
			byte params[8] = { NULL };
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* Conv_FloatToString(float InFloat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14536);
			byte params[16] = { NULL };
			*(float*)params = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_IntToString(int InInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14539);
			byte params[16] = { NULL };
			*(int*)params = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_BoolToString(bool InBool)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14542);
			byte params[16] = { NULL };
			*(bool*)params = InBool;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_VectorToString(Vector InVec)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14545);
			byte params[24] = { NULL };
			*(Vector*)params = InVec;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Conv_RotatorToString(Rotator InRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14548);
			byte params[24] = { NULL };
			*(Rotator*)params = InRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		Vector MakeVector(float X, float Y, float Z)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14551);
			byte params[24] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void BreakVector(Vector InVec, float& X, float& Y, float& Z)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14557);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14562);
			byte params[24] = { NULL };
			*(float*)params = Pitch;
			*(float*)&params[4] = Yaw;
			*(float*)&params[8] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		void BreakRot(Rotator InRot, float& Pitch, float& Yaw, float& Roll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14568);
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
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AddComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Template)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14573);
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Template;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		void DMCCreate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14576);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DMCTakeDamage(int DamageAmount, Vector HitLocation, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14577);
			byte params[28] = { NULL };
			*(int*)params = DamageAmount;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14581);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
