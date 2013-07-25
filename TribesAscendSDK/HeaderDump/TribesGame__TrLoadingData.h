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
		ScriptArray<wchar_t> GetRandomTip(int GameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoadingData.GetRandomTip");
			byte* params = (byte*)malloc(16);
			*(int*)params = GameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoadingData.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDataFields()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoadingData.SetDataFields");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
