#pragma once
#include "Engine__Camera.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrFlagBase.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCamera_Spectator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCamera_Spectator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCamera_Spectator : public Camera
	{
	public:
		ADD_OBJECT(TrFlagBase, m_HiddenFlag)
		ADD_OBJECT(TrPawn, m_HiddenViewTargetPawn)
		ADD_VAR(::BoolProperty, m_bViewFixed3p, 0x80)
		ADD_VAR(::BoolProperty, m_bViewTargetEyes, 0x40)
		ADD_VAR(::BoolProperty, m_bFastestPlayer, 0x20)
		ADD_VAR(::BoolProperty, m_bViewVehicles, 0x10)
		ADD_VAR(::BoolProperty, m_bViewFlags, 0x8)
		ADD_VAR(::BoolProperty, m_bViewFlagStands, 0x4)
		ADD_VAR(::BoolProperty, m_bViewGenerators, 0x2)
		ADD_VAR(::BoolProperty, m_bViewCameraBookmarks, 0x1)
		ADD_VAR(::FloatProperty, m_fMaxFixedViewCamDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MinCamDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MaxCamDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnZOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCameraDistanceInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInterpedCameraDistance, 0xFFFFFFFF)
		void InitializeFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.InitializeFor");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateCamera(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.UpdateCamera");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateViewTarget(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& OutVT, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.UpdateViewTarget");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params = OutVT;
			*(float*)(params + 44) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params;
			free(params);
		}
		void ShowHiddenPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.ShowHiddenPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCamera_Spectator.SetFOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
