#pragma once
#include "TribesGame.TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrPawn.AssistInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrPawn.AssistInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AssistInfo
	{
	public:
		ADD_VAR(::FloatProperty, m_fDamagerTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_AccumulatedDamage, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, m_Damager)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
