#pragma once
#include "UTGame.UTCharInfo.CustomAIData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTCharInfo.CharacterInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTCharInfo.CharacterInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CharacterInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<CustomAIData>, AIData, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Faction, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PreviewImageMarkup, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CharName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FamilyID, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CharID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
