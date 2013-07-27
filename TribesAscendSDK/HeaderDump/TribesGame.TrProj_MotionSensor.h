#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class TrProj_MotionSensor : public TrProj_Mine
	{
	public:
		void Explode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MotionSensor.Explode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetonateObsolete(bool bDetonateFromDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MotionSensor.DetonateObsolete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDetonateFromDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
