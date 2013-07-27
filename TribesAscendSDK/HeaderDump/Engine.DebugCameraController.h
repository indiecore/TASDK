#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Player.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
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
	class DebugCameraController : public PlayerController
	{
	public:
		ADD_OBJECT(Player, OryginalPlayer, 1480)
		ADD_OBJECT(PlayerController, OryginalControllerRef, 1476)
		ADD_OBJECT(Actor, SelectedActor, 1488)
		ADD_BOOL(bIsFrozenRendering, 1472, 0x2)
		ADD_BOOL(bShowSelectedInfo, 1472, 0x1)
		ADD_STRUCT(ScriptName, UnselectKey, 1464)
		ADD_STRUCT(ScriptName, SecondaryKey, 1456)
		ADD_STRUCT(ScriptName, PrimaryKey, 1448)
		void PrimarySelect(Object::Vector HitLoc, Object::Vector HitNormal, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.PrimarySelect");
			byte params[52] = { NULL };
			*(Object::Vector*)&params[0] = HitLoc;
			*(Object::Vector*)&params[12] = HitNormal;
			*(Actor::TraceHitInfo*)&params[24] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SecondarySelect(Object::Vector HitLoc, Object::Vector HitNormal, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.SecondarySelect");
			byte params[52] = { NULL };
			*(Object::Vector*)&params[0] = HitLoc;
			*(Object::Vector*)&params[12] = HitNormal;
			*(Actor::TraceHitInfo*)&params[24] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unselect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.Unselect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnActivate(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.OnActivate");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ConsoleCommand(ScriptString* Command, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.ConsoleCommand");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Command;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		void OnDeactivate(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.OnDeactivate");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableDebugCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.DisableDebugCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NativeInputKey(int ControllerId, ScriptName Key, Object::EInputEvent Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.NativeInputKey");
			byte params[25] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = Event;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
