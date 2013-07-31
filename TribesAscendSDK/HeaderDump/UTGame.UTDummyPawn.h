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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47295);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47296);
			byte params[20] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPawnAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47300);
			byte params[4] = { NULL };
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponAmbientSound(class SoundCue* NewAmbientSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47303);
			byte params[4] = { NULL };
			*(class SoundCue**)params = NewAmbientSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Rotator GetAdjustedAimFor(class Weapon* InWeapon, Vector projStart)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47305);
			byte params[28] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(Vector*)&params[4] = projStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		void WeaponAttachmentChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47312);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47313);
			byte params[16] = { NULL };
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47316);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47318);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
