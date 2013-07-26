#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.OnlineContent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineContent
	{
	public:
		ADD_VAR(::ByteProperty, ContentType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, UserIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DeviceID, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Filename, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ContentPath, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
