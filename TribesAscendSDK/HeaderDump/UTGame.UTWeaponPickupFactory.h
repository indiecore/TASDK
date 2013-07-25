#pragma once
#include "UTGame.UTBot.h"
#include "UTGame.UTPickupFactory.h"
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeaponPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeaponPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeaponPickupFactory : public UTPickupFactory
	{
	public:
		ADD_VAR(::FloatProperty, WeaponPickupScaling, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsActive, 0x2)
		ADD_VAR(::BoolProperty, bWeaponStay, 0x1)
		ADD_OBJECT(ScriptClass, WeaponPickupClass)
		bool AllowPickup(class UTBot* Bot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.AllowPickup");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = Bot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void InitializePickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.InitializePickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupVisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.SetPickupVisible");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupHidden()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.SetPickupHidden");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.SetPickupMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckForErrors()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.CheckForErrors");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetWeaponStay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.SetWeaponStay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSleeping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.StartSleeping");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AddCustomer(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.AddCustomer");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasCustomer(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.HasCustomer");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.PickedUpBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.SpawnCopyFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.ShowActive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHidden()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.ShowHidden");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyLocalPlayerDead(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponPickupFactory.NotifyLocalPlayerDead");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
