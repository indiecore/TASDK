#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineEventsInterfaceMcp.EventUploadConfig." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EventUploadConfig
	{
	public:
		ADD_VAR(::BoolProperty, bUseCompression, 0x1)
		ADD_VAR(::FloatProperty, TimeOut, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UploadUrl, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, UploadType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
