#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Pawn.h"
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
	class PickupFactory : public NavigationPoint
	{
	public:
		ADD_OBJECT(PickupFactory, OriginalFactory, 716)
		ADD_OBJECT(PickupFactory, ReplacementFactory, 712)
		ADD_STRUCT(float, MaxDesireability, 704)
		ADD_STRUCT(float, RespawnEffectTime, 700)
		ADD_OBJECT(ScriptClass, InventoryType, 696)
		ADD_BOOL(bRespawnPaused, 692, 0x10)
		ADD_BOOL(bIsSuperItem, 692, 0x8)
		ADD_BOOL(bPredictRespawns, 692, 0x4)
		ADD_BOOL(bPickupHidden, 692, 0x2)
		ADD_BOOL(bOnlyReplicateHidden, 692, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.SpawnCopyFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadyToPickup(float MaxWait)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.ReadyToPickup");
			byte params[8] = { NULL };
			*(float*)&params[0] = MaxWait;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GiveTo(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.GiveTo");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.PickedUpBy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RecheckValidTouch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.RecheckValidTouch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetRespawnTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PickupFactory.GetRespawnTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
