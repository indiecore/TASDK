#pragma once
#include "IpDrv__TcpLink.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebConnection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.WebConnection." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WebConnection : public TcpLink
	{
	public:
		ADD_VAR(::IntProperty, ConnID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLineLength, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxValueLength, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RawBytesExpecting, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDelayCleanup, 0x1)
		ADD_OBJECT(WebApplication, Application)
		ADD_OBJECT(WebResponse, Response)
		ADD_OBJECT(WebRequest, Request)
		ADD_VAR(::StrProperty, ReceivedData, 0xFFFFFFFF)
		ADD_OBJECT(WebServer, WebServer)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
