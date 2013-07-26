#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SeqAct_ModifyProperty.PropertyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PropertyInfo
	{
	public:
		ADD_VAR(::StrProperty, PropertyValue, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bModifyProperty, 0x1)
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
