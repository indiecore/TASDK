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
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTUIDataProvider_Mutator.ShouldBeFiltered");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SupportsCurrentGameMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTUIDataProvider_Mutator.SupportsCurrentGameMode");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
