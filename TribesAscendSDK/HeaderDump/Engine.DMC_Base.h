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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.PrintString");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = InString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetWorldTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.GetWorldTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float Conv_IntToFloat(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_IntToFloat");
			byte params[8] = { NULL };
			*(int*)&params[0] = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* Conv_FloatToString(float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_FloatToString");
			byte params[16] = { NULL };
			*(float*)&params[0] = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_IntToString(int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_IntToString");
			byte params[16] = { NULL };
			*(int*)&params[0] = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_BoolToString(bool InBool)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_BoolToString");
			byte params[16] = { NULL };
			*(bool*)&params[0] = InBool;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* Conv_VectorToString(Object::Vector InVec)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_VectorToString");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = InVec;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* Conv_RotatorToString(Object::Rotator InRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.Conv_RotatorToString");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = InRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		Object::Vector MakeVector(float X, float Y, float Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.MakeVector");
			byte params[24] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Z;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		void BreakVector(Object::Vector InVec, float& X, float& Y, float& Z)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.BreakVector");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.MakeRot");
			byte params[24] = { NULL };
			*(float*)&params[0] = Pitch;
			*(float*)&params[4] = Yaw;
			*(float*)&params[8] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		void BreakRot(Object::Rotator InRot, float& Pitch, float& Yaw, float& Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.BreakRot");
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
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AddComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Template)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.AddComponent");
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Template;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		void DMCCreate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.DMCCreate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DMCTakeDamage(int DamageAmount, Object::Vector HitLocation, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.DMCTakeDamage");
			byte params[28] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DMC_Base.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
