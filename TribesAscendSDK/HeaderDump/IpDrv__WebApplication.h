#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebApplication." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.WebApplication." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WebApplication : public Object
	{
	public:
		ADD_VAR(::StrProperty, Path, 0xFFFFFFFF)
		ADD_OBJECT(WebServer, WebServer)
		ADD_OBJECT(WorldInfo, WorldInfo)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
