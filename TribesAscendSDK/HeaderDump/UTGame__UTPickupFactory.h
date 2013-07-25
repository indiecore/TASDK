#pragma once
#include "UDKBase__UDKPickupFactory.h"
#include "UTGame__UTHUD.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__SoundCue.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "Engine__Projectile.h"
#include "UTGame__UTBot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPickupFactory : public UDKPickupFactory
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, PickUpWaveForm)
		ADD_VAR(::FloatProperty, LastSeekNotificationTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasLocationSpeech, 0x1)
		ADD_VAR(::NameProperty, PickupStatName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RespawnSound)
		ADD_OBJECT(Controller, TeamOwner)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetResOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.SetResOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisablePickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.DisablePickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldCamp(class UTBot* B, float MaxWait)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.ShouldCamp");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(float*)(params + 4) = MaxWait;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void UpdateHUD(class UTHUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.UpdateHUD");
			byte* params = (byte*)malloc(4);
			*(class UTHUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RespawnEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.RespawnEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.StopsProjectile");
			byte* params = (byte*)malloc(8);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StartPulse(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* TargetEmissive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.StartPulse");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)params = TargetEmissive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPickupMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.SetPickupMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptName GetPickupStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.GetPickupStatName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void InitPickupMeshEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.InitPickupMeshEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupVisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.SetPickupVisible");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupHidden()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.SetPickupHidden");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.SetInitialState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PickedUpBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupFactory.PickedUpBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
