#pragma once
#include "Engine.GameplayEvents.GameStatGroup.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameplayEvents.GameplayEventMetaData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameplayEvents.GameplayEventMetaData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameplayEventMetaData
	{
	public:
		ADD_VAR(::IntProperty, EventDataType, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<GameStatGroup>, StatGroup, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EventName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EventID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
