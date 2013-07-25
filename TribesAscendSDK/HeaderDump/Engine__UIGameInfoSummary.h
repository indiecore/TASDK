#pragma once
#include "Engine__UIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIGameInfoSummary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIGameInfoSummary : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameSettingsClassName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsDisabled, 0x2)
		ADD_VAR(::BoolProperty, bIsTeamGame, 0x1)
		ADD_VAR(::StrProperty, MapPrefix, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameAcronym, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ClassName, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IsProviderDisabled'
	};
}
#undef ADD_VAR
