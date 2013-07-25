#pragma once
#include "Engine__GameplayEventsHandler.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Array_Mirror' for the property named 'PlayerStates'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Array_Mirror' for the property named 'TeamStates'!
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
