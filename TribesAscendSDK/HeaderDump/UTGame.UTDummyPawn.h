#pragma once
#include "UTGame.UTPawn.h"
#include "Engine.SoundCue.h"
#include "UTGame.UTSeqAct_DummyWeaponFire.h"
#include "Engine.Weapon.h"
#include "Core.Object.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTDummyPawn : public UTPawn
	{
	public:
		ADD_OBJECT(UTSeqAct_DummyWeaponFire, FireAction, 2208)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.WeaponFired");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPawnAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.SetPawnAmbientSound");
			byte params[4] = { NULL };
			*(class SoundCue**)&params[0] = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.SetWeaponAmbientSound");
			byte params[4] = { NULL };
			*(class SoundCue**)&params[0] = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* InWeapon, Object::Vector projStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(Object::Vector*)&params[4] = projStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		void WeaponAttachmentChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.WeaponAttachmentChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.GetWeaponStartTraceLocation");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		Object::Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.GetPawnViewLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDummyPawn.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
