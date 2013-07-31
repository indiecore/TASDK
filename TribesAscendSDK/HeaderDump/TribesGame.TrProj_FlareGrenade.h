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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108360);
			byte params[8] = { NULL };
			*(class TrProj_TrackingMissile**)params = Missile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108365);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HijackMissileGuidance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108366);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108371);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
