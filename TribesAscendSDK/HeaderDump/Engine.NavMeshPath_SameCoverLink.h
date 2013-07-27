#pragma once
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.CoverLink.h"
#include "Engine.NavigationHandle.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPath_SameCoverLink : public NavMeshPathConstraint
	{
	public:
		ADD_OBJECT(CoverLink, TestLink, 80)
		void SameCoverLink(class NavigationHandle* NavHandle, class CoverLink* InLink)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_SameCoverLink.SameCoverLink");
			byte params[8] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(class CoverLink**)&params[4] = InLink;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_SameCoverLink.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
