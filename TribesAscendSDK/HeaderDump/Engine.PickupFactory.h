#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PickupFactory : public NavigationPoint
	{
	public:
		ADD_OBJECT(PickupFactory, OriginalFactory)
		ADD_OBJECT(PickupFactory, ReplacementFactory)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnEffectTime, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, InventoryType)
		ADD_VAR(::BoolProperty, bRespawnPaused, 0x10)
		ADD_VAR(::BoolProperty, bIsSuperItem, 0x8)
		ADD_VAR(::BoolProperty, bPredictRespawns, 0x4)
		ADD_VAR(::BoolProperty, bPickupHidden, 0x2)
		ADD_VAR(::BoolProperty, bOnlyReplicateHidden, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializePickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.InitializePickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.SetInitialState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.SetPickupMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckForErrors()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.CheckForErrors");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.SetRespawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSleeping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.StartSleeping");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.SpawnCopyFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadyToPickup(float MaxWait)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.ReadyToPickup");
			byte* params = (byte*)malloc(8);
			*(float*)params = MaxWait;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GiveTo(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.GiveTo");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.PickedUpBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RecheckValidTouch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.RecheckValidTouch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetRespawnTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.GetRespawnTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void RespawnEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.RespawnEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupHidden()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.SetPickupHidden");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupVisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.SetPickupVisible");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DelayRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.DelayRespawn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
