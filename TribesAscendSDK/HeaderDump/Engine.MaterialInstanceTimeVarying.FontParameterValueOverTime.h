#pragma once
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#include "Engine.Font.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MaterialInstanceTimeVarying.FontParameterValueOverTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty MaterialInstanceTimeVarying.FontParameterValueOverTime." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FontParameterValueOverTime : public ParameterValueOverTime
	{
	public:
		ADD_VAR(::IntProperty, FontPage, 0xFFFFFFFF)
		ADD_OBJECT(Font, FontValue)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
