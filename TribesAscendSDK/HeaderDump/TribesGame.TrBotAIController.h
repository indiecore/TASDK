#pragma once
#include "Core.Object.h"
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
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStartJetting**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIStopJetting(class TrSeqAct_AIStopJetting* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIStopJetting");
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStopJetting**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIStartSkiing(class TrSeqAct_AIStartSkiing* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIStartSkiing");
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStartSkiing**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIStopSkiing(class TrSeqAct_AIStopSkiing* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIStopSkiing");
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStopSkiing**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIMoveToActor(class SeqAct_AIMoveToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.OnAIMoveToActor");
			byte params[4] = { NULL };
			*(class SeqAct_AIMoveToActor**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartJetting(Object::Vector Direction, float Magnitude)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.StartJetting");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			*(float*)&params[12] = Magnitude;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopJetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.StopJetting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotAIController.Possess");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
