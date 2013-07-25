#pragma once
#include "Core__Object.h"
#include "Engine__MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MorphTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MorphTarget." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MorphTarget : public Object
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, MaterialInstanceConstant)
		ADD_VAR(::NameProperty, ScalarParameterName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaterialSlotId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
