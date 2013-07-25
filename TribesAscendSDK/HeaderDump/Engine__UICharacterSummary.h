#pragma once
#include "Engine__UIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UICharacterSummary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UICharacterSummary : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::BoolProperty, bIsDisabled, 0x1)
		ADD_VAR(::StrProperty, CharacterBio, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CharacterName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ClassPathName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
