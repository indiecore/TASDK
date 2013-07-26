#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKPawn.PlayEmoteInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayEmoteInfo
	{
	public:
		ADD_VAR(::BoolProperty, bNewData, 0x1)
		ADD_VAR(::IntProperty, EmoteID, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EmoteTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
