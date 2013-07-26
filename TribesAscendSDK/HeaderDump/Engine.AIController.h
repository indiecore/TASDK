#pragma once
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.SeqAct_AIMoveToActor.h"
#include "Engine.Route.h"
#include "Core.Object.Vector.h"
#include "Engine.HUD.h"
#include "Core.Object.Rotator.h"
#include "Engine.Weapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AIController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AIController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AIController : public Controller
	{
	public:
		ADD_OBJECT(Actor, ScriptedFocus)
		ADD_VAR(::IntProperty, ScriptedRouteIndex, 0xFFFFFFFF)
		ADD_OBJECT(Route, ScriptedRoute)
		ADD_OBJECT(Actor, ScriptedMoveTarget)
		ADD_VAR(::FloatProperty, Skill, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bReverseScriptedRoute, 0x2)
		ADD_VAR(::BoolProperty, bAdjustFromWalls, 0x1)
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
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void SetTeam(int inTeamIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.SetTeam");
			byte* params = (byte*)malloc(4);
			*(int*)params = inTeamIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetPlayerViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.GetPlayerViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = out_Location;
			*(Rotator*)(params + 12) = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)(params + 12);
			free(params);
		}
		void OnAIMoveToActor(class SeqAct_AIMoveToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.OnAIMoveToActor");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_AIMoveToActor**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyWeaponFired(class Weapon* W, byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.NotifyWeaponFired");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = W;
			*(params + 4) = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyWeaponFinishedFiring(class Weapon* W, byte FireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.NotifyWeaponFinishedFiring");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = W;
			*(params + 4) = FireMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanFireWeapon(class Weapon* Wpn, byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AIController.CanFireWeapon");
			byte* params = (byte*)malloc(9);
			*(class Weapon**)params = Wpn;
			*(params + 4) = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
