#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStationCollision." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrStationCollision." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrStationCollision : public Actor
	{
	public:
		ADD_OBJECT(TrPawn, m_OccupiedPawn)
		ADD_VAR(::BoolProperty, m_bCanBeUsedDuringWarmupRound, 0x2)
		ADD_VAR(::BoolProperty, m_bOccupied, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
