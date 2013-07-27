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
			byte params[8] = { NULL };
			*(class TrProj_TrackingMissile**)&params[0] = Tracker;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
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
