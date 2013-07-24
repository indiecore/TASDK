#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PlatformCommon.TgSupportCommands." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TgSupportCommands : public Object
	{
	public:
		ADD_OBJECT(WorldInfo, WorldInfo)
		ADD_OBJECT(PlayerController, PC)
	};
}
#undef ADD_OBJECT
