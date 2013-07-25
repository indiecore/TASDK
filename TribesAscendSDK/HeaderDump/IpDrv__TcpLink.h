#pragma once
#include "IpDrv__InternetLink.h"
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
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.TcpLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TcpLink : public InternetLink
	{
	public:
		ADD_VAR(::StrProperty, RecvBuf, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, AcceptClass)
		// WARNING: Unknown structure type 'ScriptStruct IpDrv.InternetLink.IpAddr' for the property named 'RemoteAddr'!
		ADD_VAR(::ByteProperty, LinkState, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'BindPort'
		// Here lies the not-yet-implemented method 'Listen'
		// Here lies the not-yet-implemented method 'Open'
		// Here lies the not-yet-implemented method 'Close'
		// Here lies the not-yet-implemented method 'IsConnected'
		// Here lies the not-yet-implemented method 'SendText'
		// Here lies the not-yet-implemented method 'SendBinary'
		// Here lies the not-yet-implemented method 'ReadText'
		// Here lies the not-yet-implemented method 'ReadBinary'
		// Here lies the not-yet-implemented method 'Accepted'
		// Here lies the not-yet-implemented method 'Opened'
		// Here lies the not-yet-implemented method 'Closed'
		// Here lies the not-yet-implemented method 'ReceivedText'
		// Here lies the not-yet-implemented method 'ReceivedLine'
		// Here lies the not-yet-implemented method 'ReceivedBinary'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
