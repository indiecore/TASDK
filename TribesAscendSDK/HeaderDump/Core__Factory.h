#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Core.Factory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Core.Factory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Factory : public Object
	{
	public:
		ADD_VAR(::IntProperty, AutoPriority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bText, 0x8)
		ADD_VAR(::BoolProperty, bEditorImport, 0x4)
		ADD_VAR(::BoolProperty, bEditAfterNew, 0x2)
		ADD_VAR(::BoolProperty, bCreateNew, 0x1)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ContextClass)
		ADD_OBJECT(ScriptClass, SupportedClass)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
