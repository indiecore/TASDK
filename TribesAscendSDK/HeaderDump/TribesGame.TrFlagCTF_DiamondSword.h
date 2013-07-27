#pragma once
#include "TribesGame.TrFlagCTF.h"
namespace UnrealScript
{
	class TrFlagCTF_DiamondSword : public TrFlagCTF
	{
	public:
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88617);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
