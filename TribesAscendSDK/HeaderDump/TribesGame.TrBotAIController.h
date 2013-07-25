#pragma once
#include "TribesGame.TrSeqAct_AIStopSkiing.h"
#include "UTGame.UTBot.h"
#include "TribesGame.TrSeqAct_AIStartJetting.h"
#include "TribesGame.TrSeqAct_AIStopJetting.h"
#include "TribesGame.TrSeqAct_AIStartSkiing.h"
#include "Engine.SeqAct_AIMoveToActor.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class TrBotAIController : public UTBot
	{
	public:
		void OnAIStartJetting(class TrSeqAct_AIStartJetting* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIStartJetting");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_AIStartJetting**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAIStopJetting(class TrSeqAct_AIStopJetting* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIStopJetting");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_AIStopJetting**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAIStartSkiing(class TrSeqAct_AIStartSkiing* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIStartSkiing");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_AIStartSkiing**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAIStopSkiing(class TrSeqAct_AIStopSkiing* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIStopSkiing");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_AIStopSkiing**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAIMoveToActor(class SeqAct_AIMoveToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIMoveToActor");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_AIMoveToActor**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartJetting(Vector Direction, float Magnitude)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.StartJetting");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(float*)(params + 12) = Magnitude;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopJetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.StopJetting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.Possess");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
