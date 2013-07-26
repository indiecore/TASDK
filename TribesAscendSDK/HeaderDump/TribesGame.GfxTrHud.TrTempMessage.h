#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GfxTrHud.TrTempMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrTempMessage
	{
	public:
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Message, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TakeDownTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInUse, 0x1)
	};
}
#undef ADD_VAR
