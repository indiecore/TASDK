#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ManageServers." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ManageServers : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AddServerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Offset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
