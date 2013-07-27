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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void SetTeam(int inTeamIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.SetTeam");
			byte params[4] = { NULL };
			*(int*)&params[0] = inTeamIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetPlayerViewPoint(Object::Vector& out_Location, Object::Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.GetPlayerViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = out_Location;
			*(Object::Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Object::Vector*)&params[0];
			out_Rotation = *(Object::Rotator*)&params[12];
		}
		void OnAIMoveToActor(class SeqAct_AIMoveToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.OnAIMoveToActor");
			byte params[4] = { NULL };
			*(class SeqAct_AIMoveToActor**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyWeaponFired(class Weapon* W, byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.NotifyWeaponFired");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = W;
			params[4] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyWeaponFinishedFiring(class Weapon* W, byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.NotifyWeaponFinishedFiring");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = W;
			params[4] = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanFireWeapon(class Weapon* Wpn, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.CanFireWeapon");
			byte params[9] = { NULL };
			*(class Weapon**)&params[0] = Wpn;
			params[4] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
