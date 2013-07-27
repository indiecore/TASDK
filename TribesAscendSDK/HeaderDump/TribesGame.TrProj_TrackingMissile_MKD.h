#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_TrackingMissile_MKD : public TrProjectile
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109422);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
