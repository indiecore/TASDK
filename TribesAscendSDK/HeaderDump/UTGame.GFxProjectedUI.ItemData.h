#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxProjectedUI.ItemData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ItemData
	{
	public:
		ADD_VAR(::ByteProperty, ItemFrame, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ItemName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ItemInfo, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
