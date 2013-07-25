#pragma once
#include "UTGame__UTUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTUIDataProvider_Weapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_Weapon : public UTUIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Flags, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AmmoClassPath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ClassName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
