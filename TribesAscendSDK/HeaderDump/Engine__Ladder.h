#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__LadderVolume.h"
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
		// Here lies the not-yet-implemented method 'SuggestMovePreparation'
	};
}
#undef ADD_OBJECT
