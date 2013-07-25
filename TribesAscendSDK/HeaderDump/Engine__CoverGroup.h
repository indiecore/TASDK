#pragma once
#include "Engine__Info.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CoverGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CoverGroup : public Info
	{
	public:
		ADD_VAR(::FloatProperty, AutoSelectHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoSelectRadius, 0xFFFFFFFF)
		void EnableGroup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverGroup.EnableGroup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableGroup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverGroup.DisableGroup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleGroup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverGroup.ToggleGroup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverGroup.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
