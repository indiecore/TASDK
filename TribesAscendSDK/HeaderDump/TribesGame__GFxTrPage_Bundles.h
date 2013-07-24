#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Bundles." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Bundles : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, classIdRequired, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DescriptionLabel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForClassRequiredPopup, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForBundleOwnedPopup, 0x1)
		ADD_VAR(::IntProperty, selectedVendorItemId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, selectedActionIdx, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
