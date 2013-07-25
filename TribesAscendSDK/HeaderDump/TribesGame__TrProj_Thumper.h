#pragma once
#include "TribesGame__TrProjectile.h"
namespace UnrealScript
{
	class TrProj_Thumper : public TrProjectile
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Thumper.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
