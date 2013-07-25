#pragma once
#include "TribesGame.TrHUD.h"
#include "Engine.PlayerInput.h"
#include "TribesGame.TrVGSCommandList.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPlayerInput." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerInput : public PlayerInput
	{
	public:
		ADD_OBJECT(ScriptClass, m_CurrentVGSNode)
		ADD_OBJECT(TrVGSCommandList, m_VGSCommandList)
		ADD_VAR(::StrProperty, m_CurrentVGSKeySequence, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bInVGSLoadoutMode, 0x4)
		ADD_VAR(::BoolProperty, m_bInVGSClassMode, 0x2)
		ADD_VAR(::BoolProperty, m_bInVGSCaptureMode, 0x1)
		ADD_OBJECT(TrHUD, m_HUD)
		ADD_VAR(::FloatProperty, m_RightJoystickLastValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_LeftJoystickLastValue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_VGSClassId, 0xFFFFFFFF)
		bool InVGSClassMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.InVGSClassMode");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool InVGSLoadoutMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.InVGSLoadoutMode");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetVGSClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.GetVGSClassId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool PlaySpottedCommand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PlaySpottedCommand");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.AdjustMouseSensitivity");
			byte* params = (byte*)malloc(4);
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsMouseSmoothEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.IsMouseSmoothEnabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnVGSKeyPressed(ScriptName KeyPressed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.OnVGSKeyPressed");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = KeyPressed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnVGSNumKeyPressed(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.OnVGSNumKeyPressed");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayVGSCommand(byte VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PlayVGSCommand");
			byte* params = (byte*)malloc(1);
			*params = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsValidVGSTarget(class Actor* ActorUnderReticule)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.IsValidVGSTarget");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = ActorUnderReticule;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndVGS()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.EndVGS");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHUDTarget(class TrHUD* TrH)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.SetHUDTarget");
			byte* params = (byte*)malloc(4);
			*(class TrHUD**)params = TrH;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetStickAngle(float UpDown, float LeftRight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.GetStickAngle");
			byte* params = (byte*)malloc(12);
			*(float*)params = UpDown;
			*(float*)(params + 4) = LeftRight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void PushAnalogJoysticksToScaleform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PushAnalogJoysticksToScaleform");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PreProcessInput");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.PlayerInput");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlyingPitchSensitivity(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.SetFlyingPitchSensitivity");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlyingYawSensitivity(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerInput.SetFlyingYawSensitivity");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
