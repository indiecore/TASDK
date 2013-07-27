#pragma once
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Camera.h"
#include "TribesGame.TrFlagBase.h"
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
	class TrCamera_Spectator : public Camera
	{
	public:
		ADD_OBJECT(TrFlagBase, m_HiddenFlag, 1124)
		ADD_OBJECT(TrPawn, m_HiddenViewTargetPawn, 1120)
		ADD_BOOL(m_bViewFixed3p, 1116, 0x80)
		ADD_BOOL(m_bViewTargetEyes, 1116, 0x40)
		ADD_BOOL(m_bFastestPlayer, 1116, 0x20)
		ADD_BOOL(m_bViewVehicles, 1116, 0x10)
		ADD_BOOL(m_bViewFlags, 1116, 0x8)
		ADD_BOOL(m_bViewFlagStands, 1116, 0x4)
		ADD_BOOL(m_bViewGenerators, 1116, 0x2)
		ADD_BOOL(m_bViewCameraBookmarks, 1116, 0x1)
		ADD_STRUCT(float, m_fMaxFixedViewCamDistance, 1112)
		ADD_STRUCT(float, m_MinCamDistance, 1108)
		ADD_STRUCT(float, m_MaxCamDistance, 1104)
		ADD_STRUCT(float, m_fMaxSpeed, 1100)
		ADD_STRUCT(float, m_fPawnZOffset, 1096)
		ADD_STRUCT(float, m_fCameraDistanceInterpSpeed, 1092)
		ADD_STRUCT(float, m_fInterpedCameraDistance, 1088)
		void InitializeFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.InitializeFor");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateCamera(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.UpdateCamera");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateViewTarget(Camera::TViewTarget& OutVT, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.UpdateViewTarget");
			byte params[48] = { NULL };
			*(Camera::TViewTarget*)&params[0] = OutVT;
			*(float*)&params[44] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)&params[0];
		}
		void ShowHiddenPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.ShowHiddenPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.SetFOV");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
