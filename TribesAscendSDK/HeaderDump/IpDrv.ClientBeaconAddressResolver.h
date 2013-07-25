#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.ClientBeaconAddressResolver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ClientBeaconAddressResolver : public Object
	{
	public:
		ADD_VAR(::NameProperty, BeaconName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BeaconPort, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
