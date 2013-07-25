#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrLoadingData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrLoadingData : public Object
	{
	public:
		ADD_VAR(::StrProperty, RulesForBlitz, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesForCaH, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesForDaD, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesForArena, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesForRabbit, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesForTDM, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesForCTF, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapURL, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Rules, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Tip, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetRandomTip'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SetDataFields'
	};
}
#undef ADD_VAR
