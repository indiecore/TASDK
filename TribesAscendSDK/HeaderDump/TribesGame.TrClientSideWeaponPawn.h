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
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
