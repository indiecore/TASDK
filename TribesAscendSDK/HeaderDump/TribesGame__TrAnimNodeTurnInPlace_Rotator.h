#pragma once
#include "Engine__AnimNodeBlendBase.h"
#include "TribesGame__TrPawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeTurnInPlace_Rotator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeTurnInPlace_Rotator : public AnimNodeBlendBase
	{
	public:
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_OBJECT
