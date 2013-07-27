#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_Thumper : public TrProjectile
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109315);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
