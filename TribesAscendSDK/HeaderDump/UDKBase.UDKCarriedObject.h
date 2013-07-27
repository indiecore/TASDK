#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKGameObjective.h"
#include "Engine.NavigationPoint.h"
#include "Engine.TeamInfo.h"
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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKCarriedObject : public Actor
	{
	public:
		ADD_STRUCT(Vector, HUDLocation, 520)
		ADD_OBJECT(Actor, OldBaseBase, 516)
		ADD_OBJECT(Actor, OldBase, 512)
		ADD_STRUCT(Vector, HomeBaseOffset, 500)
		ADD_OBJECT(UDKGameObjective, HomeBase, 496)
		ADD_BOOL(bHome, 492, 0x1)
		ADD_STRUCT(float, LastValidAnchorTime, 484)
		ADD_OBJECT(NavigationPoint, LastAnchor, 480)
		ADD_OBJECT(TeamInfo, Team, 476)
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34748);
			byte params[12] = { NULL };
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotReachableBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34750);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnBaseChainChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34752);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34753);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
