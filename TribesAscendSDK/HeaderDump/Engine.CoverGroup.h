#pragma once
#include "Engine.Info.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class CoverGroup : public Info
	{
	public:
		enum ECoverGroupFillAction : byte
		{
			CGFA_Overwrite = 0,
			CGFA_Add = 1,
			CGFA_Remove = 2,
			CGFA_Clear = 3,
			CGFA_Cylinder = 4,
			CGFA_MAX = 5,
		};
		ADD_STRUCT(ScriptArray<Actor::ActorReference>, CoverLinkRefs, 476)
		ADD_STRUCT(float, AutoSelectHeight, 492)
		ADD_STRUCT(float, AutoSelectRadius, 488)
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
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
