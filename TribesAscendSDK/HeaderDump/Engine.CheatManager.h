#pragma once
#include "Core.Object.h"
#include "Engine.DebugCameraController.h"
#include "Engine.Weapon.h"
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
	class CheatManager : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, OwnCamera, 80)
		ADD_STRUCT(ScriptString*, ViewingFrom, 68)
		ADD_OBJECT(ScriptClass, DebugCameraControllerClass, 64)
		ADD_OBJECT(DebugCameraController, DebugCameraControllerRef, 60)
		void FXPlay(ScriptClass* aClass, ScriptString* FXAnimPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.FXPlay");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			*(ScriptString**)&params[4] = FXAnimPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FXStop(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.FXStop");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DebugAI(ScriptName Category)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DebugAI");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = Category;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EditAIByTrace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.EditAIByTrace");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DebugPause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DebugPause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ListDynamicActors()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ListDynamicActors");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FreezeFrame(float Delay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.FreezeFrame");
			byte params[4] = { NULL };
			*(float*)&params[0] = Delay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WriteToLog(ScriptString* Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.WriteToLog");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillViewedActor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.KillViewedActor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Teleport()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Teleport");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeSize(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ChangeSize");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndPath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.EndPath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Amphibious()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Amphibious");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Fly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Fly");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Walk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Walk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Ghost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Ghost");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.AllAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void God()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.God");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Slomo(float T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Slomo");
			byte params[4] = { NULL };
			*(float*)&params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetJumpZ(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.SetJumpZ");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetGravity(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.SetGravity");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeed(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.SetSpeed");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAll(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.KillAll");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAllPawns(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.KillAllPawns");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillPawns()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.KillPawns");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Avatar(ScriptName ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Avatar");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Summon(ScriptString* ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Summon");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Weapon* GiveWeapon(ScriptString* WeaponClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.GiveWeapon");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = WeaponClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Weapon**)&params[12];
		}
		void PlayersOnly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.PlayersOnly");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyFractures(float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DestroyFractures");
			byte params[4] = { NULL };
			*(float*)&params[0] = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FractureAllMeshes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.FractureAllMeshes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FractureAllMeshesToMaximizeMemoryUsage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.FractureAllMeshesToMaximizeMemoryUsage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RememberSpot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.RememberSpot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewSelf(bool bQuiet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewSelf");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bQuiet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewPlayer(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewPlayer");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewActor(ScriptName ActorName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewActor");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = ActorName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewBot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewBot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewClass(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewClass");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Loaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Loaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllWeapons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.AllWeapons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLevelStreamingStatus(ScriptName PackageName, bool bShouldBeLoaded, bool bShouldBeVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.SetLevelStreamingStatus");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = PackageName;
			*(bool*)&params[8] = bShouldBeLoaded;
			*(bool*)&params[12] = bShouldBeVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableDebugCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.EnableDebugCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitCheatManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.InitCheatManager");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LogPlaySoundCalls(bool bShouldLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.LogPlaySoundCalls");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShouldLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogParticleActivateSystemCalls(bool bShouldLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.LogParticleActivateSystemCalls");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShouldLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VerifyNavMeshObjects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.VerifyNavMeshObjects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawUnsupportingEdges(ScriptString* PawnClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DrawUnsupportingEdges");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PawnClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrintNavMeshObstacles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.PrintNavMeshObstacles");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpCoverStats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DumpCoverStats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
