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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13102);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableGroup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13103);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleGroup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13104);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13105);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
