#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__LiftCenter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LiftExit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LiftExit." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LiftExit : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bExitOnly, 0x1)
		ADD_OBJECT(LiftCenter, MyLiftCenter)
		// Here lies the not-yet-implemented method 'CanBeReachedFromLiftBy'
		// Here lies the not-yet-implemented method 'WaitForLift'
		// Here lies the not-yet-implemented method 'SuggestMovePreparation'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
