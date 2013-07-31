#pragma once
#include "Engine.Input.h"
#include "Engine.Actor.h"
#include "Engine.HUD.h"
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
namespace UnrealScript
{
	class PlayerInput : public Input
	{
	public:
		ADD_STRUCT(float, aTurn, 272)
		ADD_STRUCT(float, aLookUp, 284)
		ADD_STRUCT(float, aForward, 268)
		ADD_STRUCT(float, aStrafe, 276)
		ADD_STRUCT(float, RawJoyUp, 312)
		ADD_STRUCT(float, RawJoyRight, 316)
		ADD_STRUCT(float, aUp, 280)
		ADD_BOOL(bUsingGamepad, 216, 0x1)
		ADD_STRUCT(float, AutoUnlockTurnTime, 376)
		ADD_STRUCT(float, MouseSamplingTotal, 372)
		ADD_STRUCT(int, MouseSamples, 368)
		ADD_STRUCT(float, SmoothedMouse, 360)
		ADD_STRUCT(float, ZeroTime, 352)
		ADD_STRUCT(int, FOVSetting, 348)
		ADD_STRUCT(byte, bYAxis, 346)
		ADD_STRUCT(byte, bXAxis, 345)
		ADD_STRUCT(byte, bStrafe, 344)
		ADD_STRUCT(float, LookUpScale, 340)
		ADD_STRUCT(float, LookRightScale, 336)
		ADD_STRUCT(float, MoveStrafeSpeed, 332)
		ADD_STRUCT(float, MoveForwardSpeed, 328)
		ADD_STRUCT(float, RawJoyLookUp, 324)
		ADD_STRUCT(float, RawJoyLookRight, 320)
		ADD_STRUCT(float, aPS3Gyro, 308)
		ADD_STRUCT(float, aPS3AccelZ, 304)
		ADD_STRUCT(float, aPS3AccelY, 300)
		ADD_STRUCT(float, aPS3AccelX, 296)
		ADD_STRUCT(float, aLeftAnalogTrigger, 292)
		ADD_STRUCT(float, aRightAnalogTrigger, 288)
		ADD_STRUCT(float, aMouseY, 264)
		ADD_STRUCT(float, aMouseX, 260)
		ADD_STRUCT(float, aBaseZ, 256)
		ADD_STRUCT(float, aBaseY, 252)
		ADD_STRUCT(float, aBaseX, 248)
		ADD_STRUCT(float, FlyingYawSensitivity, 244)
		ADD_STRUCT(float, FlyingPitchSensitivity, 240)
		ADD_STRUCT(float, MouseSensitivity, 236)
		ADD_STRUCT(float, DoubleClickTime, 232)
		ADD_STRUCT(float, DoubleClickTimer, 228)
		ADD_STRUCT(ScriptName, LastAxisKeyName, 220)
		ADD_BOOL(bLockTurnUntilRelease, 216, 0x8000)
		ADD_BOOL(bEnableFOVScaling, 216, 0x4000)
		ADD_BOOL(bUseToggleZoom, 216, 0x2000)
		ADD_BOOL(bEnableMouseSmoothing, 216, 0x1000)
		ADD_BOOL(bEdgeRight, 216, 0x800)
		ADD_BOOL(bEdgeLeft, 216, 0x400)
		ADD_BOOL(bEdgeBack, 216, 0x200)
		ADD_BOOL(bEdgeForward, 216, 0x100)
		ADD_BOOL(bWasRight, 216, 0x80)
		ADD_BOOL(bWasLeft, 216, 0x40)
		ADD_BOOL(bWasBack, 216, 0x20)
		ADD_BOOL(bWasForward, 216, 0x10)
		ADD_BOOL(bInvertAirVehicles, 216, 0x8)
		ADD_BOOL(bInvertTurn, 216, 0x4)
		ADD_BOOL(bInvertMouse, 216, 0x2)
		Actor::EDoubleClickDir CheckForDoubleClickMove(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8556);
			byte params[5] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::EDoubleClickDir*)&params[4];
		}
		bool InvertMouse()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13979);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool InvertTurn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13981);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetSensitivity(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13983);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13985);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13987);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostProcessInput(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13989);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13991);
			byte params[4] = { NULL };
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMouseSmoothEnabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13993);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PlayerInput(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13995);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessInputMatching(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14000);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CatchDoubleClickInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14001);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Jump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14010);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SmartJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14011);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSmoothing()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14012);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float SmoothMouse(float aMouse, float DeltaTime, byte& SampleCount, int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14014);
			byte params[17] = { NULL };
			*(float*)params = aMouse;
			*(float*)&params[4] = DeltaTime;
			params[8] = SampleCount;
			*(int*)&params[12] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SampleCount = params[8];
			return *(float*)&params[16];
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreClientTravel(ScriptString* PendingURL, Actor::ETravelType TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14023);
			byte params[17] = { NULL };
			*(ScriptString**)params = PendingURL;
			*(Actor::ETravelType*)&params[12] = TravelType;
			*(bool*)&params[16] = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
