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
			byte* params = (byte*)malloc(4);
			*(class UTGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPowerupPickupFactory.SpawnCopyFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
