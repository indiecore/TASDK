#pragma once
#include "Core.Interface.h"
#include "GameFramework.SeqAct_GameCrowdSpawner.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class GameCrowdSpawnInterface : public Interface
	{
	public:
		void GetSpawnPosition(class SeqAct_GameCrowdSpawner* Spawner, Object::Vector& SpawnPos, Object::Rotator& SpawnRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdSpawnInterface.GetSpawnPosition");
			byte params[28] = { NULL };
			*(class SeqAct_GameCrowdSpawner**)&params[0] = Spawner;
			*(Object::Vector*)&params[4] = SpawnPos;
			*(Object::Rotator*)&params[16] = SpawnRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SpawnPos = *(Object::Vector*)&params[4];
			SpawnRot = *(Object::Rotator*)&params[16];
		}
	};
}
