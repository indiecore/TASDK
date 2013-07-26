#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrVGSCommandList.TrVGSCommand." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVGSCommand
	{
	public:
		ADD_VAR(::BoolProperty, bIsContext, 0x1)
		ADD_VAR(::StrProperty, MenuString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ChatString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KeyBindPath, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, KeyBind, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, VGSScope, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
