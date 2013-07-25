#pragma once
#include "TribesGame__TrProj_Grenade.h"
#include "TribesGame__TrProj_TrackingMissile.h"
namespace UnrealScript
{
	class TrProj_FlareGrenade : public TrProj_Grenade
	{
	public:
		float CalculateHijackMetric(class TrProj_TrackingMissile* Missile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_FlareGrenade.CalculateHijackMetric");
			byte* params = (byte*)malloc(8);
			*(class TrProj_TrackingMissile**)params = Missile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_FlareGrenade.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HijackMissileGuidance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_FlareGrenade.HijackMissileGuidance");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_FlareGrenade.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
