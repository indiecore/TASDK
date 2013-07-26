#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineGameSearch.OnlineGameSearchSortClause." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineGameSearchSortClause
	{
	public:
		ADD_VAR(::IntProperty, EntryId, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ObjectPropertyName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EntryType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SortType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
