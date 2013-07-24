#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.TcpLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.TcpLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TcpLink : public InternetLink
	{
	public:
		ADD_VAR(::StrProperty, RecvBuf, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct IpDrv.InternetLink.IpAddr' for the property named 'RemoteAddr'!
		ADD_VAR(::ByteProperty, LinkState, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
