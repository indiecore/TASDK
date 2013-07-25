#pragma once
#include "Engine__Interaction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Input." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Input : public Interaction
	{
	public:
		ADD_VAR(::FloatProperty, CurrentDeltaTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentDelta, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentEvent, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ResetInput'
		// Here lies the not-yet-implemented method 'GetBind'
		// Here lies the not-yet-implemented method 'GetBindNameFromCommandScript'
		// Here lies the not-yet-implemented method 'SetBind'
	};
}
#undef ADD_VAR
