#pragma once
#include "UTGame.UTGameReplicationInfo.h"
#include "UTGame.UTPickupFactory.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTPowerupPickupFactory : public UTPickupFactory
	{
	public:
		void AddWeaponOverlay(class UTGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPowerupPickupFactory.AddWeaponOverlay");
			byte params[4] = { NULL };
			*(class UTGameReplicationInfo**)&params[0] = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPowerupPickupFactory.SpawnCopyFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
