#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKScriptedNavigationPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKScriptedNavigationPoint : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bAnchorMustBeReachable, 0x4)
		ADD_VAR(::BoolProperty, bScriptNotifyAnchorFindingResult, 0x2)
		ADD_VAR(::BoolProperty, bScriptSpecifyEndAnchor, 0x1)
		class NavigationPoint* SpecifyEndAnchor(class Pawn* RouteFinder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKScriptedNavigationPoint.SpecifyEndAnchor");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyAnchorFindingResult(class NavigationPoint* EndAnchor, class Pawn* RouteFinder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKScriptedNavigationPoint.NotifyAnchorFindingResult");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = EndAnchor;
			*(class Pawn**)(params + 4) = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
