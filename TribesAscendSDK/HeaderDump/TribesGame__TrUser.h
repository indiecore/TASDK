#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrUser." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrUser." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrUser : public Object
	{
	public:
		ADD_VAR(::BoolProperty, m_DidLogin, 0x1)
		ADD_VAR(::IntProperty, m_ClassId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CurrencyName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_SeenNewItemsMain, 0x20)
		ADD_VAR(::StrProperty, m_Username, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_Password, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_ChoseRegion, 0x2)
		ADD_VAR(::BoolProperty, m_ChoseRegion2, 0x4)
		ADD_VAR(::BoolProperty, m_SeenNewBundlesMain, 0x40)
		ADD_OBJECT(GFxTrMenuMoviePlayer, MainMenu)
		ADD_VAR(::StrProperty, m_GameType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_SeenNewGametype, 0x10)
		ADD_VAR(::BoolProperty, m_SeenClanTags, 0x8)
		ADD_VAR(::IntProperty, CurrencyCode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
