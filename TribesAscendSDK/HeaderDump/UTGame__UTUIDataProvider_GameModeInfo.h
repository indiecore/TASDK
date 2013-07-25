#pragma once
#include "UTGame__UTUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTUIDataProvider_GameModeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_GameModeInfo : public UTUIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, GameMode, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultMap, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Prefixes, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameSettingsClass, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PreviewImageMarkup, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconVL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconUL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IconU, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IconImage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OptionSet, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameSearchClass, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
