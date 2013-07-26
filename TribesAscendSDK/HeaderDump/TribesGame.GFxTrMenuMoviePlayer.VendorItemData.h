#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxTrMenuMoviePlayer.VendorItemData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VendorItemData
	{
	public:
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LootId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Price, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
