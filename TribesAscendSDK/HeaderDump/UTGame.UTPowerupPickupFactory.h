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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48866);
			byte params[4] = { NULL };
			*(class UTGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48869);
			byte params[4] = { NULL };
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
