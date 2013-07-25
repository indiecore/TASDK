#pragma once
#include "Engine__SequenceVariable.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpData : public SequenceVariable
	{
	public:
		ADD_VAR(::BoolProperty, bShouldBakeAndPrune, 0x1)
		ADD_VAR(::FloatProperty, EdSectionEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EdSectionStart, 0xFFFFFFFF)
		ADD_OBJECT(InterpFilter, SelectedFilter)
		ADD_OBJECT(InterpCurveEdSetup, CurveEdSetup)
		ADD_VAR(::FloatProperty, PathBuildTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpLength, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
