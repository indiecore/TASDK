#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrStreamManager.GameStream." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameStream
	{
	public:
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFeatured, 0x2)
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLive, 0x1)
		ADD_VAR(::StrProperty, Viewers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ChannelName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Stream, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
