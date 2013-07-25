#pragma once
#include "Core.Interface.h"
#include "GameFramework.SeqAct_GameCrowdSpawner.h"
namespace UnrealScript
{
	class GameCrowdSpawnInterface : public Interface
	{
	public:
		void GetSpawnPosition(class SeqAct_GameCrowdSpawner* Spawner, Vector& SpawnPos, Rotator& SpawnRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdSpawnInterface.GetSpawnPosition");
			byte* params = (byte*)malloc(28);
			*(class SeqAct_GameCrowdSpawner**)params = Spawner;
			*(Vector*)(params + 4) = SpawnPos;
			*(Rotator*)(params + 16) = SpawnRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SpawnPos = *(Vector*)(params + 4);
			SpawnRot = *(Rotator*)(params + 16);
			free(params);
		}
	};
}
