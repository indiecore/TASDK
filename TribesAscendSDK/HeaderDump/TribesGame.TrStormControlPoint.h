#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStormControlPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrStormControlPoint : public TrGameObjective
	{
	public:
		ADD_VAR(::StrProperty, m_sControlPointName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLaunchTimeDescriptionPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fControlDescriptionPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMissileFlightTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMissileLaunchTrackerSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMissileLaunchTracker, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentTransitionAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTransitionSpeed, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_CurrentControlPointState, 0xFFFFFFFF)
		void OnPawnTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.OnPawnTouched");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetControlPointState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.GetControlPointState");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireMissile(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.FireMissile");
			byte* params = (byte*)malloc(1);
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginTransition(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.BeginTransition");
			byte* params = (byte*)malloc(1);
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetControlPointState(byte NewControlPointState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.SetControlPointState");
			byte* params = (byte*)malloc(1);
			*params = NewControlPointState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.GetScreenName");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
