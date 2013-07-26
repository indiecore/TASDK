#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineGameplayEvents.PlayerEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineGameplayEvents.PlayerEvent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerEvent
	{
	public:
		ADD_VAR(::IntProperty, PlayerPitchAndRoll, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerIndexAndYaw, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EventLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EventTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
