#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.MaterialInstanceConstant.h"
#include "TribesGame.TrObject.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn : public Actor
	{
	public:
		ADD_OBJECT(TrPlayerController, OwningController, 540)
		ADD_OBJECT(ScriptClass, ExtentTemplateClass, 536)
		ADD_BOOL(IsInProgress, 532, 0x4)
		ADD_BOOL(PendingDelete, 532, 0x2)
		ADD_BOOL(CheckExtentsOnSpawn, 532, 0x1)
		ADD_STRUCT(float, VehicleDist, 528)
		ADD_STRUCT(float, GameObjectiveDist, 524)
		ADD_STRUCT(float, FlagStationDist, 520)
		ADD_STRUCT(ScriptString*, DisplayName, 508)
		ADD_OBJECT(MaterialInstanceConstant, MICDisplay, 504)
		ADD_STRUCT(int, CreditCost, 500)
		ADD_STRUCT(float, DegreeOfMovement, 496)
		ADD_STRUCT(float, CooldownTime, 492)
		ADD_STRUCT(float, CallTime, 488)
		ADD_STRUCT(float, BuildupTime, 484)
		ADD_STRUCT(int, DatabaseId, 480)
		ADD_STRUCT(TrObject::ETrPlayerCallIns, CallInId, 476)
		void Initialize(int NewPrice, int NewBuildup, int NewCooldown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.Initialize");
			byte params[12] = { NULL };
			*(int*)&params[0] = NewPrice;
			*(int*)&params[4] = NewBuildup;
			*(int*)&params[8] = NewCooldown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCreditCost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.GetCreditCost");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool VerifyCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.VerifyCredits");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool VerifyPower()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.VerifyPower");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool FireCompletedCallIn(int CallInOffs, Object::Vector TargetLocation, Object::Vector TargetNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.FireCompletedCallIn");
			byte params[32] = { NULL };
			*(int*)&params[0] = CallInOffs;
			*(Object::Vector*)&params[4] = TargetLocation;
			*(Object::Vector*)&params[16] = TargetNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
