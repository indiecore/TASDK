#pragma once
#include "Engine.Pawn.h"
#include "Engine.Info.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Route : public Info
	{
	public:
		enum ERouteDirection : byte
		{
			ERD_Forward = 0,
			ERD_Reverse = 1,
			ERD_MAX = 2,
		};
		enum ERouteFillAction : byte
		{
			RFA_Overwrite = 0,
			RFA_Add = 1,
			RFA_Remove = 2,
			RFA_Clear = 3,
			RFA_MAX = 4,
		};
		enum ERouteType : byte
		{
			ERT_Linear = 0,
			ERT_Loop = 1,
			ERT_Circle = 2,
			ERT_MAX = 3,
		};
		ADD_STRUCT(ScriptArray<Actor::ActorReference>, RouteList, 484)
		ADD_STRUCT(Route::ERouteType, RouteType, 480)
		ADD_STRUCT(Object::Pointer, VfTable_IEditorLinkSelectionInterface, 476)
		ADD_STRUCT(float, FudgeFactor, 496)
		ADD_STRUCT(int, RouteIndexOffset, 500)
		int ResolveRouteIndex(int Idx, Route::ERouteDirection RouteDirection, byte& out_bComplete, byte& out_bReverse)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25364);
			byte params[11] = { NULL };
			*(int*)params = Idx;
			*(Route::ERouteDirection*)&params[4] = RouteDirection;
			params[5] = out_bComplete;
			params[6] = out_bReverse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_bComplete = params[5];
			out_bReverse = params[6];
			return *(int*)&params[8];
		}
		int MoveOntoRoutePath(class Pawn* P, Route::ERouteDirection RouteDirection, float DistFudgeFactor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25370);
			byte params[13] = { NULL };
			*(class Pawn**)params = P;
			*(Route::ERouteDirection*)&params[4] = RouteDirection;
			*(float*)&params[8] = DistFudgeFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
	};
}
#undef ADD_STRUCT
