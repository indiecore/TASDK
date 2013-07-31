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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37236);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37237);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitPlayerReplicationInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37238);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Slomo(float NewTimeDilation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37239);
			byte params[4] = { NULL };
			*(float*)params = NewTimeDilation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewClass(ScriptClass* aClass, bool bQuiet, bool bCheat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37241);
			byte params[12] = { NULL };
			*(ScriptClass**)params = aClass;
			*(bool*)&params[4] = bQuiet;
			*(bool*)&params[8] = bCheat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DemoViewNextPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37248);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetViewTarget(class Actor* NewViewTarget, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37252);
			byte params[20] = { NULL };
			*(class Actor**)params = NewViewTarget;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewSelf(Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37255);
			byte params[16] = { NULL };
			*(Camera::ViewTargetTransitionParams*)params = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetRealViewTarget(class PlayerReplicationInfo* NewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37257);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = NewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetPause(bool bPause, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37259);
			byte params[20] = { NULL };
			*(bool*)params = bPause;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Pause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37263);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& CameraLocation, Rotator& CameraRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37278);
			byte params[24] = { NULL };
			*(Vector*)params = CameraLocation;
			*(Rotator*)&params[12] = CameraRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CameraLocation = *(Vector*)params;
			CameraRotation = *(Rotator*)&params[12];
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37281);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
