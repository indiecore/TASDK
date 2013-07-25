#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Class." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Class : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bViewingEquip, 0x2)
		ADD_VAR(::BoolProperty, bClassLocked, 0x1)
		ADD_VAR(::IntProperty, NumRenameLoadout, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
