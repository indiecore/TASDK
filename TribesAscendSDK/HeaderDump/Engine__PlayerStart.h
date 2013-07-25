#pragma once
#include "Engine__NavigationPoint.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PlayerStart." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerStart : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::BoolProperty, bPrimaryStart, 0x2)
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerStart.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
