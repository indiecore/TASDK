#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxEngine.GCReference." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxEngine.GCReference." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GCReference
	{
	public:
		ADD_VAR(::IntProperty, m_statid, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_count, 0xFFFFFFFF)
		ADD_OBJECT(Object, m_object)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
