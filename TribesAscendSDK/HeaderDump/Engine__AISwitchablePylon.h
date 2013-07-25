#pragma once
#include "Engine__Pylon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AISwitchablePylon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AISwitchablePylon : public Pylon
	{
	public:
		ADD_VAR(::BoolProperty, bOpen, 0x1)
	};
}
#undef ADD_VAR
