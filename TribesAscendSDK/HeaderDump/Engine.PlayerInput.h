#pragma once
#include "Engine.Input.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerInput : public Input
	{
	public:
		ADD_VAR(::FloatProperty, aTurn, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aLookUp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aForward, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aStrafe, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RawJoyUp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RawJoyRight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aUp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUsingGamepad, 0x1)
		ADD_VAR(::FloatProperty, AutoUnlockTurnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MouseSamplingTotal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MouseSamples, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SmoothedMouse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZeroTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FOVSetting, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bYAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bXAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bStrafe, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookUpScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookRightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MoveStrafeSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MoveForwardSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RawJoyLookUp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RawJoyLookRight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aPS3Gyro, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aPS3AccelZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aPS3AccelY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aPS3AccelX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aLeftAnalogTrigger, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aRightAnalogTrigger, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aMouseY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aMouseX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aBaseZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aBaseY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, aBaseX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlyingYawSensitivity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlyingPitchSensitivity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MouseSensitivity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleClickTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleClickTimer, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LastAxisKeyName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLockTurnUntilRelease, 0x8000)
		ADD_VAR(::BoolProperty, bEnableFOVScaling, 0x4000)
		ADD_VAR(::BoolProperty, bUseToggleZoom, 0x2000)
		ADD_VAR(::BoolProperty, bEnableMouseSmoothing, 0x1000)
		ADD_VAR(::BoolProperty, bEdgeRight, 0x800)
		ADD_VAR(::BoolProperty, bEdgeLeft, 0x400)
		ADD_VAR(::BoolProperty, bEdgeBack, 0x200)
		ADD_VAR(::BoolProperty, bEdgeForward, 0x100)
		ADD_VAR(::BoolProperty, bWasRight, 0x80)
		ADD_VAR(::BoolProperty, bWasLeft, 0x40)
		ADD_VAR(::BoolProperty, bWasBack, 0x20)
		ADD_VAR(::BoolProperty, bWasForward, 0x10)
		ADD_VAR(::BoolProperty, bInvertAirVehicles, 0x8)
		ADD_VAR(::BoolProperty, bInvertTurn, 0x4)
		ADD_VAR(::BoolProperty, bInvertMouse, 0x2)
		byte CheckForDoubleClickMove(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.CheckForDoubleClickMove");
			byte* params = (byte*)malloc(5);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		bool InvertMouse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.InvertMouse");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool InvertTurn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.InvertTurn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetSensitivity(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.SetSensitivity");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.DrawHUD");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.PreProcessInput");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.PostProcessInput");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.AdjustMouseSensitivity");
			byte* params = (byte*)malloc(4);
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsMouseSmoothEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.IsMouseSmoothEnabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PlayerInput(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.PlayerInput");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessInputMatching(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.ProcessInputMatching");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CatchDoubleClickInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.CatchDoubleClickInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Jump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.Jump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SmartJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.SmartJump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSmoothing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.ClearSmoothing");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float SmoothMouse(float aMouse, float DeltaTime, byte& SampleCount, int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.SmoothMouse");
			byte* params = (byte*)malloc(17);
			*(float*)params = aMouse;
			*(float*)(params + 4) = DeltaTime;
			*(params + 8) = SampleCount;
			*(int*)(params + 12) = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SampleCount = *(params + 8);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.ClientInitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreClientTravel(ScriptArray<wchar_t> PendingURL, byte TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerInput.PreClientTravel");
			byte* params = (byte*)malloc(17);
			*(ScriptArray<wchar_t>*)params = PendingURL;
			*(params + 12) = TravelType;
			*(bool*)(params + 16) = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
