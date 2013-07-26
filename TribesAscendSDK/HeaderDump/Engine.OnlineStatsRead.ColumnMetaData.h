#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineStatsRead.ColumnMetaData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ColumnMetaData
	{
	public:
		ADD_VAR(::StrProperty, ColumnName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Name, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Id, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
