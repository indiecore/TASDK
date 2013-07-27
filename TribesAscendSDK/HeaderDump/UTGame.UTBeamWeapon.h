#pragma once
#include "UTGame.UTWeapon.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.HUD.h"
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
	class UTBeamWeapon : public UTWeapon
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, BeamWeaponFireWaveForm, 1560)
		ADD_STRUCT(ScriptName, BeamPostFireAnim, 1544)
		ADD_STRUCT(ScriptName, BeamFireAnim, 1528)
		ADD_STRUCT(ScriptName, BeamPreFireAnim, 1512)
		ADD_STRUCT(ScriptName, EndPointParamName, 1504)
		ADD_STRUCT(ScriptName, BeamSockets, 1488)
		ADD_OBJECT(ParticleSystem, BeamTemplate, 1472)
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bHide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateBeamEmitter(Object::Vector FlashLocation, Object::Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.UpdateBeamEmitter");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = FlashLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			*(class Actor**)&params[24] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessBeamHit(Object::Vector StartTrace, Object::Vector AimDir, Actor::ImpactInfo& TestImpact, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.ProcessBeamHit");
			byte params[108] = { NULL };
			*(Object::Vector*)&params[0] = StartTrace;
			*(Object::Vector*)&params[12] = AimDir;
			*(Actor::ImpactInfo*)&params[24] = TestImpact;
			*(float*)&params[104] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TestImpact = *(Actor::ImpactInfo*)&params[24];
		}
		void UpdateBeam(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.UpdateBeam");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeapon.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
