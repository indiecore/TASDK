#pragma once
#include "UDKBase.UDKPlayerInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTPlayerInput : public UDKPlayerInput
	{
	public:
		ADD_VAR(::ByteProperty, ForcedDoubleClick, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHoldDuck, 0x1)
		ADD_VAR(::FloatProperty, LastDuckTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
