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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12628);
			byte params[16] = { NULL };
			*(ScriptClass**)params = aClass;
			*(ScriptString**)&params[4] = FXAnimPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FXStop(ScriptClass* aClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12638);
			byte params[4] = { NULL };
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DebugAI(ScriptName Category)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12644);
			byte params[8] = { NULL };
			*(ScriptName*)params = Category;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EditAIByTrace()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12646);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DebugPause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12653);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ListDynamicActors()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12654);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FreezeFrame(float Delay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12655);
			byte params[4] = { NULL };
			*(float*)params = Delay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WriteToLog(ScriptString* Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12658);
			byte params[12] = { NULL };
			*(ScriptString**)params = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillViewedActor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12660);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Teleport()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12661);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeSize(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12667);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndPath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12669);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Amphibious()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12670);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Fly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12671);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Walk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12674);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Ghost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12677);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12680);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void God()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12681);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Slomo(float T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12682);
			byte params[4] = { NULL };
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetJumpZ(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12684);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetGravity(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12686);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeed(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12689);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAll(ScriptClass* aClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12691);
			byte params[4] = { NULL };
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillAllPawns(ScriptClass* aClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12694);
			byte params[4] = { NULL };
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillPawns()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12699);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Avatar(ScriptName ClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12700);
			byte params[8] = { NULL };
			*(ScriptName*)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Summon(ScriptString* ClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12707);
			byte params[12] = { NULL };
			*(ScriptString**)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Weapon* GiveWeapon(ScriptString* WeaponClassStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12711);
			byte params[16] = { NULL };
			*(ScriptString**)params = WeaponClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Weapon**)&params[12];
		}
		void PlayersOnly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12720);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyFractures(float Radius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12722);
			byte params[4] = { NULL };
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FractureAllMeshes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12725);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FractureAllMeshesToMaximizeMemoryUsage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12727);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RememberSpot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12729);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewSelf(bool bQuiet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12730);
			byte params[4] = { NULL };
			*(bool*)params = bQuiet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewPlayer(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12732);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewActor(ScriptName ActorName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12735);
			byte params[8] = { NULL };
			*(ScriptName*)params = ActorName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewBot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12738);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewClass(ScriptClass* aClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12742);
			byte params[4] = { NULL };
			*(ScriptClass**)params = aClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Loaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12747);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllWeapons()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12748);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLevelStreamingStatus(ScriptName PackageName, bool bShouldBeLoaded, bool bShouldBeVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12749);
			byte params[16] = { NULL };
			*(ScriptName*)params = PackageName;
			*(bool*)&params[8] = bShouldBeLoaded;
			*(bool*)&params[12] = bShouldBeVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableDebugCamera()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12755);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitCheatManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12761);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LogPlaySoundCalls(bool bShouldLog)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12762);
			byte params[4] = { NULL };
			*(bool*)params = bShouldLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogParticleActivateSystemCalls(bool bShouldLog)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12764);
			byte params[4] = { NULL };
			*(bool*)params = bShouldLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VerifyNavMeshObjects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12766);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawUnsupportingEdges(ScriptString* PawnClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12767);
			byte params[12] = { NULL };
			*(ScriptString**)params = PawnClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrintNavMeshObstacles()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12769);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpCoverStats()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12770);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
