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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72181);
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStartJetting**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIStopJetting(class TrSeqAct_AIStopJetting* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72187);
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStopJetting**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIStartSkiing(class TrSeqAct_AIStartSkiing* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72191);
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStartSkiing**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIStopSkiing(class TrSeqAct_AIStopSkiing* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72196);
			byte params[4] = { NULL };
			*(class TrSeqAct_AIStopSkiing**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAIMoveToActor(class SeqAct_AIMoveToActor* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72200);
			byte params[4] = { NULL };
			*(class SeqAct_AIMoveToActor**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartJetting(Vector Direction, float Magnitude)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72202);
			byte params[16] = { NULL };
			*(Vector*)params = Direction;
			*(float*)&params[12] = Magnitude;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopJetting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72207);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72209);
			byte params[8] = { NULL };
			*(class Pawn**)params = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
