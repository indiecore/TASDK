#pragma once
#include "TribesGame.TrPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDemoRecSpectator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDemoRecSpectator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDemoRecSpectator : public TrPlayerController
	{
	public:
		ADD_VAR(::FloatProperty, AutoSwitchPlayerInterval, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, MyRealViewTarget)
		ADD_VAR(::BoolProperty, bAutoSwitchPlayers, 0x4)
		ADD_VAR(::BoolProperty, bLockRotationToViewTarget, 0x2)
		ADD_VAR(::BoolProperty, bFindPlayer, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.ReceivedPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitPlayerReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.InitPlayerReplicationInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Slomo(float NewTimeDilation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.Slomo");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewTimeDilation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewClass(ScriptClass* aClass, bool bQuiet, bool bCheat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.ViewClass");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = aClass;
			*(bool*)(params + 4) = bQuiet;
			*(bool*)(params + 8) = bCheat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DemoViewNextPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.DemoViewNextPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetViewTarget(class Actor* NewViewTarget, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams'!
void* TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.SetViewTarget");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = NewViewTarget;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams'!
void**)(params + 4) = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewSelf(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams'!
void* TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.ServerViewSelf");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams'!
void**)params = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetRealViewTarget(class PlayerReplicationInfo* NewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.ClientSetRealViewTarget");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = NewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetPause(bool bPause, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.SetPause");
			byte* params = (byte*)malloc(20);
			*(bool*)params = bPause;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void Pause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.Pause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& CameraLocation, Rotator& CameraRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.GetPlayerViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = CameraLocation;
			*(Rotator*)(params + 12) = CameraRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CameraLocation = *(Vector*)params;
			CameraRotation = *(Rotator*)(params + 12);
			free(params);
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDemoRecSpectator.UpdateRotation");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
