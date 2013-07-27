#pragma once
#include "UTGame.UTPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Camera.h"
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
	class DemoRecSpectator : public UTPlayerController
	{
	public:
		ADD_STRUCT(float, AutoSwitchPlayerInterval, 2184)
		ADD_OBJECT(PlayerReplicationInfo, MyRealViewTarget, 2180)
		ADD_BOOL(bAutoSwitchPlayers, 2176, 0x4)
		ADD_BOOL(bLockRotationToViewTarget, 2176, 0x2)
		ADD_BOOL(bFindPlayer, 2176, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.ReceivedPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitPlayerReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.InitPlayerReplicationInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Slomo(float NewTimeDilation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.Slomo");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewTimeDilation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewClass(ScriptClass* aClass, bool bQuiet, bool bCheat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.ViewClass");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = aClass;
			*(bool*)&params[4] = bQuiet;
			*(bool*)&params[8] = bCheat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DemoViewNextPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.DemoViewNextPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetViewTarget(class Actor* NewViewTarget, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.SetViewTarget");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = NewViewTarget;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewSelf(Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.ServerViewSelf");
			byte params[16] = { NULL };
			*(Camera::ViewTargetTransitionParams*)&params[0] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetRealViewTarget(class PlayerReplicationInfo* NewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.ClientSetRealViewTarget");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = NewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetPause(bool bPause, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.SetPause");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bPause;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Pause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.Pause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Object::Vector& CameraLocation, Object::Rotator& CameraRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.GetPlayerViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = CameraLocation;
			*(Object::Rotator*)&params[12] = CameraRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CameraLocation = *(Object::Vector*)&params[0];
			CameraRotation = *(Object::Rotator*)&params[12];
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.DemoRecSpectator.UpdateRotation");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
