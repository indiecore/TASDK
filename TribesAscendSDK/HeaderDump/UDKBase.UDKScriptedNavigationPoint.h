#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Pawn.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
namespace UnrealScript
{
	class UDKScriptedNavigationPoint : public NavigationPoint
	{
	public:
		ADD_BOOL(bAnchorMustBeReachable, 692, 0x4)
		ADD_BOOL(bScriptNotifyAnchorFindingResult, 692, 0x2)
		ADD_BOOL(bScriptSpecifyEndAnchor, 692, 0x1)
		class NavigationPoint* SpecifyEndAnchor(class Pawn* RouteFinder)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35324);
			byte params[8] = { NULL };
			*(class Pawn**)params = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[4];
		}
		void NotifyAnchorFindingResult(class NavigationPoint* EndAnchor, class Pawn* RouteFinder)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35327);
			byte params[8] = { NULL };
			*(class NavigationPoint**)params = EndAnchor;
			*(class Pawn**)&params[4] = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
