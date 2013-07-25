#pragma once
#include "Engine__AnimNodeBlendBySpeed.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendBySpeed." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendBySpeed." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendBySpeed : public AnimNodeBlendBySpeed
	{
	public:
		ADD_VAR(::BoolProperty, m_bIgnoreZVelocity, 0x1)
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
