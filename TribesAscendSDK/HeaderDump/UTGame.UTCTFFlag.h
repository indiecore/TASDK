#pragma once
#include "UTGame.UTCarriedObject.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PlayerController.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFFlag." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTCTFFlag." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFFlag." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFFlag : public UTCarriedObject
	{
	public:
		ADD_VAR(::FloatProperty, LastLocationPingTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HoverboardingClothVelClamp, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RunningClothVelClamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasClothEnabled, 0x10)
		ADD_VAR(::BoolProperty, bRespawning, 0x8)
		ADD_VAR(::BoolProperty, bFadingOut, 0x4)
		ADD_VAR(::BoolProperty, bBringDownFromBright, 0x2)
		ADD_VAR(::BoolProperty, bBringUpBright, 0x1)
		ADD_OBJECT(ParticleSystem, RespawnEffect)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnBaseChainChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.OnBaseChainChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldMinimapRenderFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.ShouldMinimapRenderFor");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.ClientReturnedHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.SetHolder");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ValidHolder(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.ValidHolder");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SameTeamTouch(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.SameTeamTouch");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CustomRespawnEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.CustomRespawnEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void bringUpBrightOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.bringUpBrightOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CustomFadeOutEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.CustomFadeOutEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Drop(class Controller* Killer, bool bNoThrow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.Drop");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(bool*)(params + 4) = bNoThrow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlagPropertiesToStationaryFlagState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.SetFlagPropertiesToStationaryFlagState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFlagDynamicLightToNotBeDynamic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFFlag.SetFlagDynamicLightToNotBeDynamic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
