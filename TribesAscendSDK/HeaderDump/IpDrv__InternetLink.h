#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.InternetLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.InternetLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InternetLink : public Info
	{
	public:
		ADD_VAR(::IntProperty, DataPending, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'PrivateResolveInfo'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RemoteSocket'!
		ADD_VAR(::IntProperty, Port, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Socket'!
		ADD_VAR(::ByteProperty, ReceiveMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OutLineMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LinkMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InLineMode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
