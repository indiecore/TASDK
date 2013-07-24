#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_VendorTable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_VendorTable : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, UserInputString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DescriptionLabel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DollMeshId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VendorId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, selectedVendorItemId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, selectedActionIdx, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
