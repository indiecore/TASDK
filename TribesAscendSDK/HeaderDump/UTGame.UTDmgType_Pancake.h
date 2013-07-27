#pragma once
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTDmgType_RanOver.h"
namespace UnrealScript
{
	class UTDmgType_Pancake : public UTDmgType_RanOver
	{
	public:
		void SmallReward(class UTPlayerController* Killer, int KillCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_Pancake.SmallReward");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = Killer;
			*(int*)&params[4] = KillCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
