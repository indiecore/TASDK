#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataProvider.UIDataProviderField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProviderField
	{
	public:
		ADD_VAR(::ByteProperty, FieldType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FieldTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
