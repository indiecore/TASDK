#pragma once
#include "Engine.GameplayEventsHandler.h"
#include "Core.Object.Array_Mirror.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameStateObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameStateObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameStateObject : public GameplayEventsHandler
	{
	public:
		ADD_VAR(::IntProperty, MaxRoundNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundNumber, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsRoundStarted, 0x2)
		ADD_VAR(::BoolProperty, bIsMatchStarted, 0x1)
		ADD_VAR(::ByteProperty, SessionType, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Array_Mirror>, PlayerStates, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Array_Mirror>, TeamStates, 0xFFFFFFFF)
		void PreProcessStream()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameStateObject.PreProcessStream");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameStateObject.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
