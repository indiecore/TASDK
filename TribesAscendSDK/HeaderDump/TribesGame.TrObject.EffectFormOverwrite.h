#pragma once
#include "Engine.Material.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObject.EffectFormOverwrite." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrObject.EffectFormOverwrite." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EffectFormOverwrite
	{
	public:
		ADD_OBJECT(Material, Mat)
		ADD_VAR(::ByteProperty, eType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
