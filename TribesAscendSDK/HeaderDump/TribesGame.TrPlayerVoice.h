#pragma once
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
namespace UnrealScript
{
	class TrPlayerVoice : public TrDevice
	{
	public:
		void PlaySoundEx(byte Command, class TrPlayerController* TrPC, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerVoice.PlaySoundEx");
			byte* params = (byte*)malloc(9);
			*params = Command;
			*(class TrPlayerController**)(params + 4) = TrPC;
			*(class PlayerReplicationInfo**)(params + 8) = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlaySoundContext(class TrPlayerController* TrPC, byte ContextActor, byte ContextLocation, bool bEnemyLocation, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerVoice.PlaySoundContext");
			byte* params = (byte*)malloc(14);
			*(class TrPlayerController**)params = TrPC;
			*(params + 4) = ContextActor;
			*(params + 5) = ContextLocation;
			*(bool*)(params + 8) = bEnemyLocation;
			*(class PlayerReplicationInfo**)(params + 12) = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRandomSample(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerVoice.PlayRandomSample");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
