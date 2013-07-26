#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.FireLinkItem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FireLinkItem
	{
	public:
		ADD_VAR(::ByteProperty, DestAction, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DestType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SrcAction, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SrcType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
