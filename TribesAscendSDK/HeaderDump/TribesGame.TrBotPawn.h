#pragma once
#include "TribesGame.TrPlayerPawn.h"
namespace UnrealScript
{
	class TrBotPawn : public TrPlayerPawn
	{
	public:
		void SetMovementPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotPawn.SetMovementPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotPawn.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RechargeHealthPool(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBotPawn.RechargeHealthPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
