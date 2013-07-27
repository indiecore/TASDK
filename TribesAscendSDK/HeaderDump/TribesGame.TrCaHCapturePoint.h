#pragma once
#include "Core.Object.h"
#include "TribesGame.TrRepairStation_Neutral.h"
#include "Engine.Actor.h"
#include "TribesGame.TrGameObjective.h"
#include "TribesGame.TrRadarStation_Neutral.h"
#include "TribesGame.TrBaseTurret_Neutral.h"
#include "TribesGame.TrInventoryStation_Neutral.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrObject.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.MaterialInstanceConstant.h"
#include "TribesGame.TrPawn.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
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
	class TrCaHCapturePoint : public TrGameObjective
	{
	public:
		class NearbyPlayer
		{
		public:
			ADD_STRUCT(float, LastCheckedTimestamp, 8)
			ADD_STRUCT(float, Time, 4)
			ADD_OBJECT(TrPlayerController, NearbyPC, 0)
		};
		ADD_STRUCT(ScriptArray<class TrBaseTurret_Neutral*>, m_BaseTurrets, 1372)
		ADD_STRUCT(ScriptArray<class TrRadarStation_Neutral*>, m_BaseSensors, 1384)
		ADD_STRUCT(ScriptArray<class TrInventoryStation_Neutral*>, m_InventoryStations, 1396)
		ADD_STRUCT(ScriptArray<class TrRepairStation_Neutral*>, m_RepairStations, 1408)
		ADD_STRUCT(ScriptArray<TrCaHCapturePoint::NearbyPlayer>, m_NearbyPlayers, 1580)
		ADD_STRUCT(float, m_HoldTheLineAccoladeTime, 1596)
		ADD_STRUCT(float, m_fNearbyPawnCheckTime, 1592)
		ADD_OBJECT(TrPlayerController, m_LastCapturedBy, 1576)
		ADD_STRUCT(float, m_fPointPulseMarkerSpeed, 1572)
		ADD_STRUCT(float, m_fPointPulseMarkerTime, 1568)
		ADD_STRUCT(float, m_fRemainingPointPulseMarkerTime, 1564)
		ADD_STRUCT(float, m_fPulseMarkerSpeed, 1560)
		ADD_STRUCT(float, m_fPulseMarkerTime, 1556)
		ADD_STRUCT(float, m_fRemainingPulseMarkerTime, 1552)
		ADD_STRUCT(float, m_MarkerSize, 1548)
		ADD_STRUCT(byte, r_nFlashPointPulse, 1545)
		ADD_STRUCT(TrObject::CaHCapturePointLabel, m_CapturePointLabel, 1544)
		ADD_BOOL(r_bIsHeld, 1540, 0x1)
		ADD_STRUCT(Object::Vector, LastCameraPos, 1528)
		ADD_STRUCT(Object::Vector, LastCameraDir, 1516)
		ADD_STRUCT(Object::Vector, LastScreenLoc, 1504)
		ADD_STRUCT(float, m_fInfluenceRadiusSize, 1500)
		ADD_OBJECT(SkelControlSingleBone, m_SkyHologramSkelControl, 1496)
		ADD_STRUCT(float, m_fSkyHologramScaleDS, 1492)
		ADD_STRUCT(float, m_fSkyHologramScaleBE, 1488)
		ADD_STRUCT(float, m_fSkyHologramScaleOffset, 1484)
		ADD_STRUCT(Object::Vector, m_vSkyHologramOffsetDS, 1472)
		ADD_STRUCT(Object::Vector, m_vSkyHologramOffsetBE, 1460)
		ADD_STRUCT(float, m_fSkyHologramOffsetZ, 1456)
		ADD_STRUCT(float, m_fSkyHologramOffsetY, 1452)
		ADD_STRUCT(float, m_fSkyHologramOffsetX, 1448)
		ADD_OBJECT(MaterialInstanceConstant, m_DiamondSwordHologramMIC, 1444)
		ADD_OBJECT(MaterialInstanceConstant, m_BloodEagleHologramMIC, 1440)
		ADD_STRUCT(ScriptString*, m_sCapturePointName, 1360)
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
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.OnPawnTouched");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		ScriptString* GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.GetScreenName");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckNearbyPlayersTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.CheckNearbyPlayersTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPawnConsideredNearby(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHCapturePoint.IsPawnConsideredNearby");
			byte params[8] = { NULL };
			*(class TrPawn**)&params[0] = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
