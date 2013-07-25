#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.LadderVolume.h"
#include "Engine.Pawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Ladder." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Ladder : public NavigationPoint
	{
	public:
		ADD_OBJECT(Ladder, LadderList)
		ADD_OBJECT(LadderVolume, MyLadder)
		bool SuggestMovePreparation(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Ladder.SuggestMovePreparation");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
