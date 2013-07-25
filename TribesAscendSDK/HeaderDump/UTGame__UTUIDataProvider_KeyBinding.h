#pragma once
#include "UTGame__UTUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTUIDataProvider_KeyBinding." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_KeyBinding : public UTUIResourceDataProvider
	{
	public:
		ADD_VAR(::BoolProperty, bIsCrucialBind, 0x1)
		ADD_VAR(::StrProperty, Command, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
