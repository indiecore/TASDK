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
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTUIDataProvider_SettingsMenuItem.ShouldBeFiltered");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
