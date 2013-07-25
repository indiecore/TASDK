#pragma once
#include "Core.Object.h"
#include "Engine.DebugCameraController.h"
#include "Engine.Weapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CheatManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CheatManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CheatManager : public Object
	{
	public:
		ADD_VAR(::StrProperty, OwnCamera, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ViewingFrom, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DebugCameraControllerClass)
		ADD_OBJECT(DebugCameraController, DebugCameraControllerRef)
		void FXPlay(ScriptClass* aClass, ScriptArray<wchar_t> FXAnimPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.FXPlay");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = aClass;
			*(ScriptArray<wchar_t>*)(params + 4) = FXAnimPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FXStop(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.FXStop");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DebugAI(ScriptName Category)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DebugAI");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = Category;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = Delay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WriteToLog(ScriptArray<wchar_t> Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.WriteToLog");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetJumpZ(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.SetJumpZ");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetGravity(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.SetGravity");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpeed(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.SetSpeed");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KillAll(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.KillAll");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KillAllPawns(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.KillAllPawns");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KillPawns()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.KillPawns");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Avatar(ScriptName ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Avatar");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Summon(ScriptArray<wchar_t> ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.Summon");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Weapon* GiveWeapon(ScriptArray<wchar_t> WeaponClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.GiveWeapon");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = WeaponClassStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Weapon**)(params + 12);
			free(params);
			return returnVal;
		}
		void PlayersOnly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.PlayersOnly");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyFractures(float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DestroyFractures");
			byte* params = (byte*)malloc(4);
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bQuiet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewPlayer(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewPlayer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewActor(ScriptName ActorName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewActor");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = ActorName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewBot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewBot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewClass(ScriptClass* aClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.ViewClass");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = PackageName;
			*(bool*)(params + 8) = bShouldBeLoaded;
			*(bool*)(params + 12) = bShouldBeVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShouldLog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogParticleActivateSystemCalls(bool bShouldLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.LogParticleActivateSystemCalls");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShouldLog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VerifyNavMeshObjects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.VerifyNavMeshObjects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawUnsupportingEdges(ScriptArray<wchar_t> PawnClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CheatManager.DrawUnsupportingEdges");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PawnClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
#undef ADD_VAR
#undef ADD_OBJECT
