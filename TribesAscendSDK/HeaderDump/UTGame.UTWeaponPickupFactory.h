#pragma once
#include "UTGame.UTBot.h"
#include "UTGame.UTPickupFactory.h"
#include "UTGame.UTWeaponLocker.h"
#include "Engine.PlayerController.h"
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
	class UTWeaponPickupFactory : public UTPickupFactory
	{
	public:
		ADD_STRUCT(ScriptArray<UTWeaponLocker::PawnToucher>, Customers, 960)
		ADD_STRUCT(float, WeaponPickupScaling, 956)
		ADD_BOOL(bIsActive, 948, 0x2)
		ADD_BOOL(bWeaponStay, 948, 0x1)
		ADD_OBJECT(ScriptClass, WeaponPickupClass, 944)
		bool AllowPickup(class UTBot* Bot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40958);
			byte params[8] = { NULL };
			*(class UTBot**)params = Bot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InitializePickup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50329);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupVisible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50331);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupHidden()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50332);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50333);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50334);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckForErrors()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50336);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetWeaponStay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50338);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSleeping()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50339);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AddCustomer(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50340);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasCustomer(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50345);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50351);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50353);
			byte params[4] = { NULL };
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50356);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHidden()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50357);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyLocalPlayerDead(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50358);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
