#pragma once
#include "Engine.CoverLink.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.CoverInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty CoverLink.CoverInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CoverInfo
	{
	public:
		ADD_OBJECT(CoverLink, Link)
		ADD_VAR(::IntProperty, SlotIdx, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
