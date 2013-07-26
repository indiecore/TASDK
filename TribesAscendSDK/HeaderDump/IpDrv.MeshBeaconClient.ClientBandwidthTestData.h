#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MeshBeaconClient.ClientBandwidthTestData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ClientBandwidthTestData
	{
	public:
		ADD_VAR(::FloatProperty, ElapsedTestTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumBytesSentLast, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumBytesSentTotal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumBytesToSendTotal, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentState, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TestType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
