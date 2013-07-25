#pragma once
#include "UTGame__UTUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTUIDataProvider_SettingsMenuItem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_SettingsMenuItem : public UTUIResourceDataProvider
	{
	public:
		ADD_VAR(::BoolProperty, bFrontEndOnly, 0x1)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ShouldBeFiltered'
	};
}
#undef ADD_VAR
