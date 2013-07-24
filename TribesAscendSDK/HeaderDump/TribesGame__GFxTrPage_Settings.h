#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Settings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Settings : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, C1P3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, C1P2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, C1P1, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForCheatCodePopup, 0x1)
		ADD_VAR(::IntProperty, CheatCodeAction, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
