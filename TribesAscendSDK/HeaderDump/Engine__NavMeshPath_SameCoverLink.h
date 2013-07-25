#pragma once
#include "Engine__CoverLink.h"
#include "Engine__NavMeshPathConstraint.h"
#include "Engine__NavigationHandle.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavMeshPath_SameCoverLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPath_SameCoverLink : public NavMeshPathConstraint
	{
	public:
		ADD_OBJECT(CoverLink, TestLink)
		void SameCoverLink(class NavigationHandle* NavHandle, class CoverLink* InLink)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_SameCoverLink.SameCoverLink");
			byte* params = (byte*)malloc(8);
			*(class NavigationHandle**)params = NavHandle;
			*(class CoverLink**)(params + 4) = InLink;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPath_SameCoverLink.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
