#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
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
	class ReachSpec : public Object
	{
	public:
		static const auto BLOCKEDPATHCOST = 10000000;
		ADD_STRUCT(ScriptArray<ScriptClass*>, PruneSpecList, 128)
		ADD_OBJECT(Actor, BlockedBy, 140)
		ADD_BOOL(bDisabled, 124, 0x10)
		ADD_BOOL(bSkipPrune, 124, 0x8)
		ADD_BOOL(bCheckForObstructions, 124, 0x4)
		ADD_BOOL(bCanCutCorners, 124, 0x2)
		ADD_BOOL(bAddToNavigationOctree, 124, 0x1)
		ADD_STRUCT(byte, PathColorIndex, 121)
		ADD_STRUCT(byte, bPruned, 120)
		ADD_STRUCT(int, MaxLandingVelocity, 116)
		ADD_STRUCT(int, reachFlags, 112)
		ADD_STRUCT(int, CollisionHeight, 108)
		ADD_STRUCT(int, CollisionRadius, 104)
		ADD_STRUCT(Actor::ActorReference, End, 84)
		ADD_OBJECT(NavigationPoint, Start, 80)
		ADD_STRUCT(Vector, Direction, 68)
		ADD_STRUCT(int, Distance, 64)
		ADD_STRUCT(Object::Pointer, NavOctreeObject, 60)
		int CostFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9671);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class NavigationPoint* GetEnd()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9674);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)params;
		}
		Vector GetDirection()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9676);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		bool IsBlockedFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9678);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
