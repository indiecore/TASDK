#pragma once
#include "Core__Object.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEffect : public Object
	{
	public:
		ADD_OBJECT(ScriptClass, m_EffectFormClass)
		ADD_VAR(::FloatProperty, m_fValue, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bRemovable, 0x1)
		ADD_VAR(::ByteProperty, m_eCalcMethodCode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nEffectInstanceId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Apply'
		// Here lies the not-yet-implemented method 'Remove'
		// Here lies the not-yet-implemented method 'CanBeApplied'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
