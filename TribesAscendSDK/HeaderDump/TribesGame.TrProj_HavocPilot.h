#pragma once
#include "TribesGame.TrProjectile.h"
#include "TribesGame.TrProj_TrackingMissile.h"
namespace UnrealScript
{
	class TrProj_HavocPilot : public TrProjectile
	{
	public:
		float CalculateHijackMetric(class TrProj_TrackingMissile* Tracker)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_HavocPilot.CalculateHijackMetric");
			byte* params = (byte*)malloc(8);
			*(class TrProj_TrackingMissile**)params = Tracker;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_HavocPilot.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HijackMissileGuidance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_HavocPilot.HijackMissileGuidance");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_HavocPilot.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
