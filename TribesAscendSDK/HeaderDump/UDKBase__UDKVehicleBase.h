#pragma once
#include "Engine__SVehicle.h"
#include "UDKBase__UDKCarriedObject.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKVehicleBase : public SVehicle
	{
	public:
		ADD_VAR(::BoolProperty, bShouldEject, 0x1)
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.HoldGameObject");
			byte* params = (byte*)malloc(4);
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.SwitchWeapon");
			byte* params = (byte*)malloc(1);
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.AdjacentSeat");
			byte* params = (byte*)malloc(8);
			*(int*)params = Direction;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerAdjacentSeat(int Direction, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.ServerAdjacentSeat");
			byte* params = (byte*)malloc(8);
			*(int*)params = Direction;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerChangeSeat(int RequestedSeat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.ServerChangeSeat");
			byte* params = (byte*)malloc(4);
			*(int*)params = RequestedSeat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetDamageScaling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.GetDamageScaling");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool NeedToTurn(Vector targ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.NeedToTurn");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = targ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.DrivingStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.DriverEnter");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ApplyWeaponEffects(int OverlayFlags, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.ApplyWeaponEffects");
			byte* params = (byte*)malloc(8);
			*(int*)params = OverlayFlags;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptName GetVehicleDrivingStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.GetVehicleDrivingStatName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void EjectDriver()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.EjectDriver");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.DetachDriver");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte ChooseFireMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.ChooseFireMode");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.BotFire");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StopFiringWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.StopFiringWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleDeadVehicleDriver()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleBase.HandleDeadVehicleDriver");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
