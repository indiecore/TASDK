#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_TC24 : public TrProjectile
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109270);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
