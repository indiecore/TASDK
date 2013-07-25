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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
