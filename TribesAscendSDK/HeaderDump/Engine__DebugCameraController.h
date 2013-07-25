#pragma once
#include "Engine__PlayerController.h"
#include "Engine__Player.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DebugCameraController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DebugCameraController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DebugCameraController : public PlayerController
	{
	public:
		ADD_OBJECT(Player, OryginalPlayer)
		ADD_OBJECT(PlayerController, OryginalControllerRef)
		ADD_OBJECT(Actor, SelectedActor)
		ADD_VAR(::BoolProperty, bIsFrozenRendering, 0x2)
		ADD_VAR(::BoolProperty, bShowSelectedInfo, 0x1)
		ADD_VAR(::NameProperty, UnselectKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SecondaryKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PrimaryKey, 0xFFFFFFFF)
		void PrimarySelect(Vector HitLoc, Vector HitNormal, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.PrimarySelect");
			byte* params = (byte*)malloc(52);
			*(Vector*)params = HitLoc;
			*(Vector*)(params + 12) = HitNormal;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 24) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SecondarySelect(Vector HitLoc, Vector HitNormal, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.SecondarySelect");
			byte* params = (byte*)malloc(52);
			*(Vector*)params = HitLoc;
			*(Vector*)(params + 12) = HitNormal;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 24) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> ConsoleCommand(ScriptArray<wchar_t> Command, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.ConsoleCommand");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Command;
			*(bool*)(params + 12) = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
			return returnVal;
		}
		void OnDeactivate(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.OnDeactivate");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisableDebugCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.DisableDebugCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NativeInputKey(int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraController.NativeInputKey");
			byte* params = (byte*)malloc(25);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = Key;
			*(params + 12) = Event;
			*(float*)(params + 16) = AmountDepressed;
			*(bool*)(params + 20) = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
