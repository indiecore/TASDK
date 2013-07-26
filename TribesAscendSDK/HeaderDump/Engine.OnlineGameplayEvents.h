#pragma once
#include "Core.Object.h"
#include "Core.Object.Guid.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineGameplayEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineGameplayEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineGameplayEvents : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Guid>, GameplaySessionID, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGameplaySessionInProgress, 0x1)
		ADD_VAR(::StrProperty, GameplaySessionStartTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
