#pragma once
#include "Engine.DecalManager.h"
namespace UnrealScript
{
	class UTDecalManager : public DecalManager
	{
	public:
		bool CanSpawnDecals()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDecalManager.CanSpawnDecals");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
