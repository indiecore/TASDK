#pragma once
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " HUD.ConsoleMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty HUD.ConsoleMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty HUD.ConsoleMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ConsoleMessage
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, PRI)
		ADD_VAR(::FloatProperty, MessageLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, TextColor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Text, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
