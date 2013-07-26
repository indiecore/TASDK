#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrQueueManager.RentalItem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RentalItem
	{
	public:
		ADD_VAR(::StrProperty, RentalName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Price, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LootId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SortOrder, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
