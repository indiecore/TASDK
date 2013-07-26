#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_DynamicResource.DynamicResourceProviderDefinition." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UIDataStore_DynamicResource.DynamicResourceProviderDefinition." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DynamicResourceProviderDefinition
	{
	public:
		ADD_OBJECT(ScriptClass, ProviderClass)
		ADD_VAR(::StrProperty, ProviderClassName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ProviderTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
