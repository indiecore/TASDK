#pragma once
#include "UTGame.UTWeapon.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTBeamWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTBeamWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTBeamWeapon : public UTWeapon
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, BeamWeaponFireWaveForm)
		ADD_VAR(::NameProperty, BeamPostFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamPreFireAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EndPointParamName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeamSockets, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, BeamTemplate)
		void AddBeamEmitter()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.AddBeamEmitter");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillBeamEmitter()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.KillBeamEmitter");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBeamEmitterHidden(bool bHide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.SetBeamEmitterHidden");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bHide;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateBeamEmitter(Vector FlashLocation, Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.UpdateBeamEmitter");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = FlashLocation;
			*(Vector*)(params + 12) = HitNormal;
			*(class Actor**)(params + 24) = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessBeamHit(Vector StartTrace, Vector AimDir, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void*& TestImpact, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.ProcessBeamHit");
			byte* params = (byte*)malloc(108);
			*(Vector*)params = StartTrace;
			*(Vector*)(params + 12) = AimDir;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 24) = TestImpact;
			*(float*)(params + 104) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			TestImpact = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 24);
			free(params);
		}
		void UpdateBeam(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.UpdateBeam");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
