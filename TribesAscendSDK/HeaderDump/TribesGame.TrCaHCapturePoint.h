#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Engine.Actor.h"
#include "TribesGame.TrPlayerController.h"
#include "Core.Object.Vector.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCaHCapturePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrCaHCapturePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCaHCapturePoint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCaHCapturePoint : public TrGameObjective
	{
	public:
		ADD_VAR(::FloatProperty, m_HoldTheLineAccoladeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fNearbyPawnCheckTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, m_LastCapturedBy)
		ADD_VAR(::FloatProperty, m_fPointPulseMarkerSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPointPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingPointPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseMarkerSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingPulseMarkerTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_MarkerSize, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nFlashPointPulse, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CapturePointLabel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bIsHeld, 0x1)
		ADD_STRUCT(::VectorProperty, LastCameraPos, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastCameraDir, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastScreenLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInfluenceRadiusSize, 0xFFFFFFFF)
		ADD_OBJECT(SkelControlSingleBone, m_SkyHologramSkelControl)
		ADD_VAR(::FloatProperty, m_fSkyHologramScaleDS, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramScaleBE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramScaleOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vSkyHologramOffsetDS, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vSkyHologramOffsetBE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramOffsetZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkyHologramOffsetX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_DiamondSwordHologramMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_BloodEagleHologramMIC)
		ADD_VAR(::StrProperty, m_sCapturePointName, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PulseMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.PulseMarker");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PointPulseMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.PointPulseMarker");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateHologramVisibility()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.UpdateHologramVisibility");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.OnPawnTouched");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostCapturePointTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.PostCapturePointTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardPointTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.AwardPointTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldPostRenderForCaH()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.ShouldPostRenderForCaH");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.GetScreenName");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckNearbyPlayersTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.CheckNearbyPlayersTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPawnConsideredNearby(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.IsPawnConsideredNearby");
			byte* params = (byte*)malloc(8);
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
