#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Settings.SettingsPropertyPropertyMetaData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SettingsPropertyPropertyMetaData
	{
	public:
		ADD_VAR(::IntProperty, Id, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Name, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ColumnHeaderText, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MappingType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinVal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxVal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RangeIncrement, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
