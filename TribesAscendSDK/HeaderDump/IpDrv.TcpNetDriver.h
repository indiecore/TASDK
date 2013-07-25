#pragma once
#include "Engine.NetDriver.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.TcpNetDriver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TcpNetDriver : public NetDriver
	{
	public:
		ADD_VAR(::BoolProperty, AllowPlayerPortUnreach, 0x1)
		ADD_VAR(::BoolProperty, LogPortUnreach, 0x1)
	};
}
#undef ADD_VAR
