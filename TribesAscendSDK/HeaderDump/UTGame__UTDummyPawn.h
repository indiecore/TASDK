#pragma once
#include "Engine__SoundCue.h"
#include "UTGame__UTPawn.h"
#include "UTGame__UTSeqAct_DummyWeaponFire.h"
#include "Engine__Weapon.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDummyPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDummyPawn : public UTPawn
	{
	public:
		ADD_OBJECT(UTSeqAct_DummyWeaponFire, FireAction)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.WeaponFired");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPawnAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.SetPawnAmbientSound");
			byte* params = (byte*)malloc(4);
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWeaponAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.SetWeaponAmbientSound");
			byte* params = (byte*)malloc(4);
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Rotator GetAdjustedAimFor(class Weapon* InWeapon, Vector projStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.GetAdjustedAimFor");
			byte* params = (byte*)malloc(28);
			*(class Weapon**)params = InWeapon;
			*(Vector*)(params + 4) = projStart;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		void WeaponAttachmentChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.WeaponAttachmentChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.GetWeaponStartTraceLocation");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.GetPawnViewLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
