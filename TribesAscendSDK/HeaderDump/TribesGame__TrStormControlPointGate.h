#pragma once
#include "TribesGame__TrGameObjective.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrStormControlPointGate." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrStormControlPointGate : public TrGameObjective
	{
	public:
		ADD_OBJECT(TrStormControlPoint, m_ControlPoint)
	};
}
#undef ADD_OBJECT
