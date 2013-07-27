#pragma once
#include "TribesGame.TrHUD.h"
#include "Engine.PlayerInput.h"
#include "TribesGame.TrVGSCommandList.h"
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
	class TrPlayerInput : public PlayerInput
	{
	public:
		ADD_OBJECT(ScriptClass, m_CurrentVGSNode, 436)
		ADD_OBJECT(TrVGSCommandList, m_VGSCommandList, 440)
		ADD_STRUCT(ScriptArray<ScriptName>, m_VGSPassThroughKeys, 400)
		ADD_STRUCT(ScriptArray<ScriptName>, m_VGSNumKeys, 412)
		ADD_STRUCT(ScriptArray<ScriptName>, m_VGSPadKeys, 424)
		ADD_STRUCT(ScriptString*, m_CurrentVGSKeySequence, 444)
		ADD_BOOL(m_bInVGSLoadoutMode, 396, 0x4)
		ADD_BOOL(m_bInVGSClassMode, 396, 0x2)
		ADD_BOOL(m_bInVGSCaptureMode, 396, 0x1)
		ADD_OBJECT(TrHUD, m_HUD, 392)
		ADD_STRUCT(float, m_RightJoystickLastValue, 388)
		ADD_STRUCT(float, m_LeftJoystickLastValue, 384)
		ADD_STRUCT(int, m_VGSClassId, 380)
		bool InVGSClassMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.InVGSClassMode");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool InVGSLoadoutMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.InVGSLoadoutMode");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetVGSClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.GetVGSClassId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool PlaySpottedCommand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PlaySpottedCommand");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.AdjustMouseSensitivity");
			byte params[4] = { NULL };
			*(float*)&params[0] = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMouseSmoothEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.IsMouseSmoothEnabled");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnVGSKeyPressed(ScriptName KeyPressed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.OnVGSKeyPressed");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = KeyPressed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnVGSNumKeyPressed(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.OnVGSNumKeyPressed");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVGSCommand(TrVGSCommandList::VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PlayVGSCommand");
			byte params[1] = { NULL };
			*(TrVGSCommandList::VGSCommandType*)&params[0] = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsValidVGSTarget(class Actor* ActorUnderReticule)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.IsValidVGSTarget");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = ActorUnderReticule;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StartVGS()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.StartVGS");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartVGSClasses()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.StartVGSClasses");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartVGSLoadouts(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.StartVGSLoadouts");
			byte params[4] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndVGS()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.EndVGS");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHUDTarget(class TrHUD* TrH)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.SetHUDTarget");
			byte params[4] = { NULL };
			*(class TrHUD**)&params[0] = TrH;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetStickAngle(float UpDown, float LeftRight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.GetStickAngle");
			byte params[12] = { NULL };
			*(float*)&params[0] = UpDown;
			*(float*)&params[4] = LeftRight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void PushAnalogJoysticksToScaleform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PushAnalogJoysticksToScaleform");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PreProcessInput");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PlayerInput");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlyingPitchSensitivity(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.SetFlyingPitchSensitivity");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlyingYawSensitivity(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.SetFlyingYawSensitivity");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
