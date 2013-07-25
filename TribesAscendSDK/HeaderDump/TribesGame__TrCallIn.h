#pragma once
#include "Engine__Actor.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn : public Actor
	{
	public:
		ADD_OBJECT(TrPlayerController, OwningController)
		ADD_OBJECT(ScriptClass, ExtentTemplateClass)
		ADD_VAR(::BoolProperty, IsInProgress, 0x4)
		ADD_VAR(::BoolProperty, PendingDelete, 0x2)
		ADD_VAR(::BoolProperty, CheckExtentsOnSpawn, 0x1)
		ADD_VAR(::FloatProperty, VehicleDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GameObjectiveDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlagStationDist, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DisplayName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, MICDisplay)
		ADD_VAR(::IntProperty, CreditCost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DegreeOfMovement, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CooldownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CallTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BuildupTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DatabaseId, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CallInId, 0xFFFFFFFF)
		void Initialize(int NewPrice, int NewBuildup, int NewCooldown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.Initialize");
			byte* params = (byte*)malloc(12);
			*(int*)params = NewPrice;
			*(int*)(params + 4) = NewBuildup;
			*(int*)(params + 8) = NewCooldown;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetCreditCost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.GetCreditCost");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool VerifyCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.VerifyCredits");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool VerifyPower()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.VerifyPower");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool FireCompletedCallIn(int CallInOffs, Vector TargetLocation, Vector TargetNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.FireCompletedCallIn");
			byte* params = (byte*)malloc(32);
			*(int*)params = CallInOffs;
			*(Vector*)(params + 4) = TargetLocation;
			*(Vector*)(params + 16) = TargetNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
