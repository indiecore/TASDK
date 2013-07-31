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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108432);
			byte params[8] = { NULL };
			*(class TrProj_TrackingMissile**)params = Tracker;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108435);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HijackMissileGuidance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108436);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108438);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
