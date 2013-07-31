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
		struct NearbyPlayer
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
		ADD_STRUCT(Vector, LastCameraPos, 1528)
		ADD_STRUCT(Vector, LastCameraDir, 1516)
		ADD_STRUCT(Vector, LastScreenLoc, 1504)
		ADD_STRUCT(float, m_fInfluenceRadiusSize, 1500)
		ADD_OBJECT(SkelControlSingleBone, m_SkyHologramSkelControl, 1496)
		ADD_STRUCT(float, m_fSkyHologramScaleDS, 1492)
		ADD_STRUCT(float, m_fSkyHologramScaleBE, 1488)
		ADD_STRUCT(float, m_fSkyHologramScaleOffset, 1484)
		ADD_STRUCT(Vector, m_vSkyHologramOffsetDS, 1472)
		ADD_STRUCT(Vector, m_vSkyHologramOffsetBE, 1460)
		ADD_STRUCT(float, m_fSkyHologramOffsetZ, 1456)
		ADD_STRUCT(float, m_fSkyHologramOffsetY, 1452)
		ADD_STRUCT(float, m_fSkyHologramOffsetX, 1448)
		ADD_OBJECT(MaterialInstanceConstant, m_DiamondSwordHologramMIC, 1444)
		ADD_OBJECT(MaterialInstanceConstant, m_BloodEagleHologramMIC, 1440)
		ADD_STRUCT(ScriptString*, m_sCapturePointName, 1360)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73788);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73791);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PulseMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73793);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PointPulseMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73794);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateHologramVisibility()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73795);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73797);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73799);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73805);
			byte params[4] = { NULL };
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostCapturePointTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73813);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardPointTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73817);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldPostRenderForCaH()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73819);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		ScriptString* GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73821);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73824);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckNearbyPlayersTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73835);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPawnConsideredNearby(class TrPawn* TRP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73840);
			byte params[8] = { NULL };
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
