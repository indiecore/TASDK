#pragma once
#include "Core__Object.h"
#include "IpDrv__WebConnection.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebResponse." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.WebResponse." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.WebResponse." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WebResponse : public Object
	{
	public:
		ADD_OBJECT(WebConnection, Connection)
		ADD_VAR(::BoolProperty, bSentResponse, 0x2)
		ADD_VAR(::BoolProperty, bSentText, 0x1)
		ADD_VAR(::StrProperty, CharSet, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IncludePath, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'ReplacementMap'!
		// Here lies the not-yet-implemented method 'Subst'
		// Here lies the not-yet-implemented method 'IncludeUHTM'
		// Here lies the not-yet-implemented method 'FileExists'
		// Here lies the not-yet-implemented method 'IncludeBinaryFile'
		// Here lies the not-yet-implemented method 'ClearSubst'
		// Here lies the not-yet-implemented method 'LoadParsedUHTM'
		// Here lies the not-yet-implemented method 'GetHTTPExpiration'
		// Here lies the not-yet-implemented method 'Dump'
		// Here lies the not-yet-implemented method 'SendText'
		// Here lies the not-yet-implemented method 'SendBinary'
		// Here lies the not-yet-implemented method 'SendCachedFile'
		// Here lies the not-yet-implemented method 'FailAuthentication'
		// Here lies the not-yet-implemented method 'HTTPResponse'
		// Here lies the not-yet-implemented method 'HTTPHeader'
		// Here lies the not-yet-implemented method 'AddHeader'
		// Here lies the not-yet-implemented method 'SendHeaders'
		// Here lies the not-yet-implemented method 'HTTPError'
		// Here lies the not-yet-implemented method 'SendStandardHeaders'
		// Here lies the not-yet-implemented method 'Redirect'
		// Here lies the not-yet-implemented method 'SentText'
		// Here lies the not-yet-implemented method 'SentResponse'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
