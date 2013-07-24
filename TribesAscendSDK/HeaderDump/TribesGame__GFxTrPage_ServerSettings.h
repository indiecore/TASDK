#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerSettings : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bPopup, 0x1)
		ADD_VAR(::IntProperty, PopupNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LocalNameNumber, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
