#pragma once
#include "TribesGame__TrPaperDoll.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPaperDollTransient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPaperDollTransient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPaperDollTransient : public TrPaperDoll
	{
	public:
		ADD_VAR(::FloatProperty, m_fBackdropFadeRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBackdropFadeTime, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_BackdropMIC)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
