#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebRequest." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.WebRequest." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WebRequest : public Object
	{
	public:
		ADD_VAR(::StrProperty, UserName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Password, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URI, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RequestType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RemoteAddr, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ContentLength, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ContentType, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'VariableMap'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'HeaderMap'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
