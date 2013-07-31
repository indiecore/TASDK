#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "TribesGame.TrAnimNodeTurnInPlace.h"
#include "TribesGame.TrPawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeTurnInPlace_Rotator : public AnimNodeBlendBase
	{
	public:
		ADD_STRUCT(ScriptArray<class TrAnimNodeTurnInPlace*>, c_TurnInPlaceNodes, 248)
		ADD_OBJECT(TrPawn, m_TrPawn, 244)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
