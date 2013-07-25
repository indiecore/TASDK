#pragma once
#include "UTGame__UTUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTUIDataProvider_Mutator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_Mutator : public UTUIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, ClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GroupNames, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOfficialMutator, 0x2)
		ADD_VAR(::BoolProperty, bStandaloneOnly, 0x1)
		// Here lies the not-yet-implemented method 'ShouldBeFiltered'
		// Here lies the not-yet-implemented method 'SupportsCurrentGameMode'
	};
}
#undef ADD_VAR
