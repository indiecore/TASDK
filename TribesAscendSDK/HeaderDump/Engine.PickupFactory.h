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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24480);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24482);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializePickup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24483);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24484);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24485);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24486);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24487);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckForErrors()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24488);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetRespawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24493);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSleeping()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24494);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24495);
			byte params[12] = { NULL };
			*(class Pawn**)params = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24499);
			byte params[4] = { NULL };
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadyToPickup(float MaxWait)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24502);
			byte params[8] = { NULL };
			*(float*)params = MaxWait;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GiveTo(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24505);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24507);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RecheckValidTouch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24510);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetRespawnTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24533);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void RespawnEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24535);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupHidden()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24536);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupVisible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24537);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24538);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DelayRespawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24548);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
