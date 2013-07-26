#pragma once
#include "Engine.Settings.h"
#include "Engine.OnlineGameSearch.OverrideSkill.h"
#include "Engine.Settings.LocalizedStringSetting.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchQuery.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.OnlineGameSearch." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineGameSearch : public Settings
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<OverrideSkill>, ManualSkillOverride, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxSearchResults, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LocalizedStringSetting>, Query, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsLanQuery, 0x1)
		ADD_VAR(::BoolProperty, bUsesArbitration, 0x2)
		ADD_VAR(::BoolProperty, bIsSearchInProgress, 0x4)
		ADD_OBJECT(ScriptClass, GameSettingsClass)
		ADD_STRUCT(::NonArithmeticProperty<OnlineGameSearchQuery>, FilterQuery, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AdditionalSearchCriteria, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PingBucketSize, 0xFFFFFFFF)
		void SortSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameSearch.SortSearchResults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSkillOverride(int LeaderboardId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameSearch.SetSkillOverride");
			byte* params = (byte*)malloc(16);
			*(int*)params = LeaderboardId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
