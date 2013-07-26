#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MeshBeacon.ConnectionBandwidthStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ConnectionBandwidthStats
	{
	public:
		ADD_VAR(::IntProperty, RoundtripLatency, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DownstreamRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, UpstreamRate, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
