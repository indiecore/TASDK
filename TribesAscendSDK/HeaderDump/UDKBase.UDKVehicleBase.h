#pragma once
#include "Engine.SVehicle.h"
#include "UDKBase.UDKCarriedObject.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
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
namespace UnrealScript
{
	class UDKVehicleBase : public SVehicle
	{
	public:
		ADD_BOOL(bShouldEject, 1544, 0x1)
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35766);
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35768);
			byte params[1] = { NULL };
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35770);
			byte params[8] = { NULL };
			*(int*)params = Direction;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35773);
			byte params[8] = { NULL };
			*(int*)params = Direction;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35776);
			byte params[4] = { NULL };
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetDamageScaling()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35778);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool NeedToTurn(Vector targ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35780);
			byte params[16] = { NULL };
			*(Vector*)params = targ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35786);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35787);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35791);
			byte params[8] = { NULL };
			*(int*)params = OverlayFlags;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetVehicleDrivingStatName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35794);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void EjectDriver()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35797);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35800);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte ChooseFireMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35803);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35807);
			byte params[8] = { NULL };
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StopFiringWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35811);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35812);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleDeadVehicleDriver()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35814);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
