#pragma once
#include "UTGame__UTBot.h"
#include "UTGame__UTPickupFactory.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeaponLocker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTWeaponLocker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeaponLocker." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeaponLocker : public UTPickupFactory
	{
	public:
		ADD_VAR(::FloatProperty, NextProximityCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScaleRate, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, WeaponSpawnEffectTemplate)
		ADD_OBJECT(ParticleSystem, ActiveEffectTemplate)
		ADD_OBJECT(ParticleSystem, InactiveEffectTemplate)
		ADD_VAR(::FloatProperty, ProximityDistanceSquared, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentWeaponScaleX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bScalingUp, 0x4)
		ADD_VAR(::BoolProperty, bPlayerNearby, 0x2)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::StrProperty, LockerString, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UTGame.UTWeaponLocker.ReplacementWeaponEntry' for the property named 'ReplacementWeapons'!
		float BotDesireability(class Pawn* Bot, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.BotDesireability");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Bot;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetInitialState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.SetInitialState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldCamp(class UTBot* B, float MaxWait)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ShouldCamp");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(float*)(params + 4) = MaxWait;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AddCustomer(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.AddCustomer");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasCustomer(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.HasCustomer");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeWeapons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.InitializeWeapons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplaceWeapon(int Index, ScriptClass* NewWeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ReplaceWeapon");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(ScriptClass**)(params + 4) = NewWeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void InitializePickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.InitializePickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ShowActive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyLocalPlayerDead(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.NotifyLocalPlayerDead");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerNearby(class PlayerController* PC, bool bNewPlayerNearby, bool bPlayEffects)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.SetPlayerNearby");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = PC;
			*(bool*)(params + 4) = bNewPlayerNearby;
			*(bool*)(params + 8) = bPlayEffects;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DestroyWeapons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.DestroyWeapons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHidden()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTWeaponLocker.ShowHidden");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
