#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.SeqAct_AIMoveToActor.h"
#include "Engine.Route.h"
#include "Engine.HUD.h"
#include "Engine.Weapon.h"
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
	class AIController : public Controller
	{
	public:
		ADD_OBJECT(Actor, ScriptedFocus, 920)
		ADD_STRUCT(int, ScriptedRouteIndex, 916)
		ADD_OBJECT(Route, ScriptedRoute, 912)
		ADD_OBJECT(Actor, ScriptedMoveTarget, 908)
		ADD_STRUCT(float, Skill, 904)
		ADD_BOOL(bReverseScriptedRoute, 900, 0x2)
		ADD_BOOL(bAdjustFromWalls, 900, 0x1)
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9716);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9718);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9719);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void SetTeam(int inTeamIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9728);
			byte params[4] = { NULL };
			*(int*)params = inTeamIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetPlayerViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9730);
			byte params[24] = { NULL };
			*(Vector*)params = out_Location;
			*(Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)&params[12];
		}
		void OnAIMoveToActor(class SeqAct_AIMoveToActor* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9733);
			byte params[4] = { NULL };
			*(class SeqAct_AIMoveToActor**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyWeaponFired(class Weapon* W, byte FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9748);
			byte params[5] = { NULL };
			*(class Weapon**)params = W;
			params[4] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyWeaponFinishedFiring(class Weapon* W, byte FireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9751);
			byte params[5] = { NULL };
			*(class Weapon**)params = W;
			params[4] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanFireWeapon(class Weapon* Wpn, byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9754);
			byte params[9] = { NULL };
			*(class Weapon**)params = Wpn;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
