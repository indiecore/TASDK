#pragma once
#include "UTGame.UTClientSideWeaponPawn.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class TrClientSideWeaponPawn : public UTClientSideWeaponPawn
	{
	public:
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrClientSideWeaponPawn.DetachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
