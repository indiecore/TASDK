#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.LadderVolume.h"
#include "Engine.Pawn.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Ladder : public NavigationPoint
	{
	public:
		ADD_OBJECT(Ladder, LadderList, 696)
		ADD_OBJECT(LadderVolume, MyLadder, 692)
		bool SuggestMovePreparation(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Ladder.SuggestMovePreparation");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_OBJECT
