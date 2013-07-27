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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53575);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool InVGSLoadoutMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53585);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetVGSClassId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53587);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool PlaySpottedCommand()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77100);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77951);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77952);
			byte params[4] = { NULL };
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMouseSmoothEnabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77954);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnVGSKeyPressed(ScriptName KeyPressed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77956);
			byte params[8] = { NULL };
			*(ScriptName*)params = KeyPressed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnVGSNumKeyPressed(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77965);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayVGSCommand(TrVGSCommandList::VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77992);
			byte params[1] = { NULL };
			*(TrVGSCommandList::VGSCommandType*)params = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsValidVGSTarget(class Actor* ActorUnderReticule)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77994);
			byte params[8] = { NULL };
			*(class Actor**)params = ActorUnderReticule;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StartVGS()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78000);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartVGSClasses()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78002);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartVGSLoadouts(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78003);
			byte params[4] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndVGS()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78005);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHUDTarget(class TrHUD* TrH)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78006);
			byte params[4] = { NULL };
			*(class TrHUD**)params = TrH;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetStickAngle(float UpDown, float LeftRight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78008);
			byte params[12] = { NULL };
			*(float*)params = UpDown;
			*(float*)&params[4] = LeftRight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void PushAnalogJoysticksToScaleform()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78015);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78018);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerInput(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78020);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlyingPitchSensitivity(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78026);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlyingYawSensitivity(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78028);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
