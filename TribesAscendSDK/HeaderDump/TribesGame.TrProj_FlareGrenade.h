#pragma once
#include "TribesGame.TrProj_Grenade.h"
#include "TribesGame.TrProj_TrackingMissile.h"
namespace UnrealScript
{
	class TrProj_FlareGrenade : public TrProj_Grenade
	{
	public:
		float CalculateHijackMetric(class TrProj_TrackingMissile* Missile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_FlareGrenade.CalculateHijackMetric");
			byte params[8] = { NULL };
			*(class TrProj_TrackingMissile**)&params[0] = Missile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
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
