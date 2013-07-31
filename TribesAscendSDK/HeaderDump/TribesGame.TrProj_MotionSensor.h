#pragma once
#include "TribesGame.TrProj_Mine.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class TrProj_MotionSensor : public TrProj_Mine
	{
	public:
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108757);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetonateObsolete(bool bDetonateFromDamage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108762);
			byte params[4] = { NULL };
			*(bool*)params = bDetonateFromDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
