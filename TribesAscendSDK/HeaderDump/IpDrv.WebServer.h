#pragma once
#include "IpDrv.TcpLink.h"
#include "IpDrv.WebApplication.h"
#include "Engine.Actor.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class WebServer : public TcpLink
	{
	public:
		ADD_STRUCT(int, ConnID, 868)
		ADD_STRUCT(int, DefaultApplication, 804)
		ADD_STRUCT(ScriptString*, ApplicationPaths, 672)
		ADD_STRUCT(int, ExpirationSeconds, 808)
		ADD_STRUCT(int, ConnectionCount, 864)
		ADD_OBJECT(WebApplication, ApplicationObjects, 824)
		ADD_STRUCT(ScriptString*, ServerURL, 812)
		ADD_STRUCT(int, MaxConnections, 800)
		ADD_STRUCT(int, ListenPort, 796)
		ADD_BOOL(bEnabled, 792, 0x1)
		ADD_STRUCT(ScriptString*, Applications, 552)
		ADD_STRUCT(ScriptString*, ServerName, 540)
		class WebApplication* GetApplication(ScriptString* URI, ScriptString*& SubURI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebServer.GetApplication");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = URI;
			*(ScriptString**)&params[12] = SubURI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SubURI = *(ScriptString**)&params[12];
			return *(class WebApplication**)&params[24];
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
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LostChild(class Actor* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebServer.LostChild");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
