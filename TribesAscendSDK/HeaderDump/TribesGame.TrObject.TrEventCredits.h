#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObject.TrEventCredits." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrEventCredits
	{
	public:
		ADD_VAR(::ByteProperty, EventType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, eventCredits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, proxyEventCredits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MsgIdx, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsBroadcast, 0x1)
	};
}
#undef ADD_VAR
