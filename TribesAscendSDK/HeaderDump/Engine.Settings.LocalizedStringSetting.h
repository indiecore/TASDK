#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Settings.LocalizedStringSetting." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LocalizedStringSetting
	{
	public:
		ADD_VAR(::IntProperty, Id, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ValueIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AdvertisementType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
