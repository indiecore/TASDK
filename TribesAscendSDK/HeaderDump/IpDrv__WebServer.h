#pragma once
#include "IpDrv__TcpLink.h"
#include "IpDrv__WebApplication.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebServer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.WebServer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WebServer : public TcpLink
	{
	public:
		ADD_VAR(::IntProperty, ConnID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DefaultApplication, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ApplicationPaths, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ExpirationSeconds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConnectionCount, 0xFFFFFFFF)
		ADD_OBJECT(WebApplication, ApplicationObjects)
		ADD_VAR(::StrProperty, ServerURL, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxConnections, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ListenPort, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::StrProperty, Applications, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ServerName, 0xFFFFFFFF)
		class WebApplication* GetApplication(ScriptArray<wchar_t> URI, ScriptArray<wchar_t>& SubURI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebServer.GetApplication");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = URI;
			*(ScriptArray<wchar_t>*)(params + 12) = SubURI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SubURI = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(class WebApplication**)(params + 24);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebServer.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebServer.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GainedChild(class Actor* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebServer.GainedChild");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LostChild(class Actor* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebServer.LostChild");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
