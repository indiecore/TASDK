#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSkin." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSkin : public Object
	{
	public:
		ADD_VAR(::StrProperty, ItemName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, InfoPanelDescription, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TranslucencySortPriority, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ItemId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
