#pragma once
#include "Engine.SoundNodeWave.h"
#include "UDKBase.UDKPickupFactory.h"
#include "Engine.Projectile.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.SoundCue.h"
#include "Core.Object.h"
#include "UTGame.UTBot.h"
#include "Engine.Controller.h"
#include "UTGame.UTHUD.h"
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
	class UTPickupFactory : public UDKPickupFactory
	{
	public:
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, LocationSpeech, 924)
		ADD_OBJECT(ForceFeedbackWaveform, PickUpWaveForm, 940)
		ADD_STRUCT(float, LastSeekNotificationTime, 936)
		ADD_BOOL(bHasLocationSpeech, 920, 0x1)
		ADD_STRUCT(ScriptName, PickupStatName, 912)
		ADD_OBJECT(SoundCue, RespawnSound, 900)
		ADD_OBJECT(Controller, TeamOwner, 884)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40402);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetResOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40403);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisablePickup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40404);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40405);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40406);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldCamp(class UTBot* B, float MaxWait)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40408);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(float*)&params[4] = MaxWait;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40414);
			byte params[4] = { NULL };
			*(class UTHUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RespawnEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40416);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40417);
			byte params[8] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StartPulse(Object::LinearColor TargetEmissive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40423);
			byte params[16] = { NULL };
			*(Object::LinearColor*)params = TargetEmissive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPickupMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40436);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptName GetPickupStatName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40437);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void InitPickupMeshEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40439);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupVisible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40440);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupHidden()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40441);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40442);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40443);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
