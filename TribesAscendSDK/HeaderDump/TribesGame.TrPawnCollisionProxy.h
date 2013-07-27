#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class TrPawnCollisionProxy : public TrCollisionProxy
	{
	public:
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100614);
			byte params[4] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100617);
			byte params[4] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
