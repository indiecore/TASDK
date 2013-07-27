#pragma once
#include "Engine.PhysicsVolume.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTScriptedBotVolume : public PhysicsVolume
	{
	public:
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49026);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
