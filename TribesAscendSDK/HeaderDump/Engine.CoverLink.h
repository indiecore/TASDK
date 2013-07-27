#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
#include "Engine.SeqAct_ModifyCover.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.Scout.h"
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
	class CoverLink : public NavigationPoint
	{
	public:
		static const float COVERLINK_DangerDist;
		static const float COVERLINK_EdgeExposureDot;
		static const float COVERLINK_EdgeCheckDot;
		static const float COVERLINK_ExposureDot;
		enum ECoverLocationDescription : byte
		{
			CoverDesc_None = 0,
			CoverDesc_InWindow = 1,
			CoverDesc_InDoorway = 2,
			CoverDesc_BehindCar = 3,
			CoverDesc_BehindTruck = 4,
			CoverDesc_OnTruck = 5,
			CoverDesc_BehindBarrier = 6,
			CoverDesc_BehindColumn = 7,
			CoverDesc_BehindCrate = 8,
			CoverDesc_BehindWall = 9,
			CoverDesc_BehindStatue = 10,
			CoverDesc_BehindSandbags = 11,
			CoverDesc_MAX = 12,
		};
		enum ECoverType : byte
		{
			CT_None = 0,
			CT_Standing = 1,
			CT_MidLevel = 2,
			CT_MAX = 3,
		};
		enum ECoverAction : byte
		{
			CA_Default = 0,
			CA_BlindLeft = 1,
			CA_BlindRight = 2,
			CA_LeanLeft = 3,
			CA_LeanRight = 4,
			CA_PopUp = 5,
			CA_BlindUp = 6,
			CA_PeekLeft = 7,
			CA_PeekRight = 8,
			CA_PeekUp = 9,
			CA_MAX = 10,
		};
		enum ECoverDirection : byte
		{
			CD_Default = 0,
			CD_Left = 1,
			CD_Right = 2,
			CD_Up = 3,
			CD_MAX = 4,
		};
		enum EFireLinkID : byte
		{
			FLI_FireLink = 0,
			FLI_RejectedFireLink = 1,
			FLI_MAX = 2,
		};
		struct CovPosInfo
		{
		public:
			ADD_OBJECT(CoverLink, Link, 0)
			ADD_STRUCT(int, LtSlotIdx, 4)
			ADD_STRUCT(int, RtSlotIdx, 8)
			ADD_STRUCT(float, LtToRtPct, 12)
			ADD_STRUCT(Vector, Location, 16)
			ADD_STRUCT(Vector, Normal, 28)
			ADD_STRUCT(Vector, Tangent, 40)
		};
		struct FireLink
		{
		public:
			ADD_STRUCT(ScriptArray<byte>, Interactions, 0)
			ADD_BOOL(bDynamicIndexInited, 16, 0x2)
			ADD_BOOL(bFallbackLink, 16, 0x1)
			ADD_STRUCT(int, PackedProperties_CoverPairRefAndDynamicInfo, 12)
		};
		struct DynamicLinkInfo
		{
		public:
			ADD_STRUCT(Vector, LastSrcLocation, 12)
			ADD_STRUCT(Vector, LastTargetLocation, 0)
		};
		struct CoverReference : public ActorReference
		{
		public:
			ADD_STRUCT(int, SlotIdx, 20)
		};
		struct SlotMoveRef
		{
		public:
			ADD_STRUCT(int, Direction, 76)
			ADD_STRUCT(Actor::BasedPosition, Dest, 24)
			ADD_STRUCT(Pylon::PolyReference, Poly, 0)
		};
		struct CoverInfo
		{
		public:
			ADD_OBJECT(CoverLink, Link, 0)
			ADD_STRUCT(int, SlotIdx, 4)
		};
		struct FireLinkItem
		{
		public:
			ADD_STRUCT(CoverLink::ECoverAction, DestAction, 3)
			ADD_STRUCT(CoverLink::ECoverType, DestType, 2)
			ADD_STRUCT(CoverLink::ECoverAction, SrcAction, 1)
			ADD_STRUCT(CoverLink::ECoverType, SrcType, 0)
		};
		struct ExposedLink
		{
		public:
			ADD_STRUCT(byte, ExposedScale, 24)
			ADD_STRUCT(CoverLink::CoverReference, TargetActor, 0)
		};
		struct CoverSlot
		{
		public:
			ADD_STRUCT(ScriptArray<CoverLink::ECoverAction>, Actions, 36)
			ADD_STRUCT(ScriptArray<CoverLink::FireLink>, FireLinks, 48)
			ADD_STRUCT(ScriptArray<CoverLink::FireLink>, RejectedFireLinks, 60)
			ADD_STRUCT(ScriptArray<int>, ExposedCoverPackedProperties, 72)
			ADD_STRUCT(ScriptArray<CoverLink::SlotMoveRef>, SlipRefs, 88)
			ADD_STRUCT(ScriptArray<CoverLink::CoverInfo>, OverlapClaimsList, 100)
			ADD_BOOL(bFailedToFindSurface, 112, 0x200000)
			ADD_BOOL(bSelected, 112, 0x100000)
			ADD_BOOL(bPlayerOnly, 112, 0x80000)
			ADD_BOOL(bForceNoGroundAdjust, 112, 0x40000)
			ADD_BOOL(bAllowSwatTurn, 112, 0x20000)
			ADD_BOOL(bAllowClimbUp, 112, 0x10000)
			ADD_BOOL(bAllowCoverSlip, 112, 0x8000)
			ADD_BOOL(bAllowMantle, 112, 0x4000)
			ADD_BOOL(bAllowPopup, 112, 0x2000)
			ADD_BOOL(bEnabled, 112, 0x1000)
			ADD_BOOL(bCanSwatTurn_Right, 112, 0x800)
			ADD_BOOL(bCanSwatTurn_Left, 112, 0x400)
			ADD_BOOL(bCanCoverSlip_Right, 112, 0x200)
			ADD_BOOL(bCanCoverSlip_Left, 112, 0x100)
			ADD_BOOL(bForceCanCoverSlip_Right, 112, 0x80)
			ADD_BOOL(bForceCanCoverSlip_Left, 112, 0x40)
			ADD_BOOL(bCanClimbUp, 112, 0x20)
			ADD_BOOL(bCanMantle, 112, 0x10)
			ADD_BOOL(bCanPopUp, 112, 0x8)
			ADD_BOOL(bForceCanPopUp, 112, 0x4)
			ADD_BOOL(bLeanRight, 112, 0x2)
			ADD_BOOL(bLeanLeft, 112, 0x1)
			ADD_STRUCT(int, TurnTargetPackedProperties, 84)
			ADD_STRUCT(Rotator, RotationOffset, 24)
			ADD_STRUCT(Vector, LocationOffset, 12)
			ADD_STRUCT(CoverLink::ECoverLocationDescription, LocationDescription, 10)
			ADD_STRUCT(CoverLink::ECoverType, CoverType, 9)
			ADD_STRUCT(CoverLink::ECoverType, ForceCoverType, 8)
			ADD_STRUCT(float, SlotValidAfterTime, 4)
			ADD_OBJECT(Pawn, SlotOwner, 0)
		};
		ADD_STRUCT(ScriptArray<CoverLink::CoverSlot>, Slots, 700)
		ADD_BOOL(bClaimAllSlots, 692, 0x4)
		ADD_STRUCT(ScriptArray<class Pawn*>, Claims, 724)
		ADD_BOOL(bCircular, 692, 0x20)
		ADD_BOOL(bDisabled, 692, 0x2)
		ADD_BOOL(bFractureOnTouch, 692, 0x200)
		ADD_BOOL(GLOBAL_bUseSlotMarkers, 692, 0x1)
		ADD_BOOL(bAutoSort, 692, 0x8)
		ADD_BOOL(bAutoAdjust, 692, 0x10)
		ADD_BOOL(bLooped, 692, 0x40)
		ADD_BOOL(bPlayerOnly, 692, 0x80)
		ADD_BOOL(bDynamicCover, 692, 0x100)
		ADD_BOOL(bDebug_FireLinks, 692, 0x400)
		ADD_BOOL(bDebug_ExposedLinks, 692, 0x800)
		ADD_BOOL(bDebug_CoverGen, 692, 0x1000)
		ADD_BOOL(bDoAutoSlotDensityFixup, 692, 0x2000)
		ADD_STRUCT(float, LeanTraceDist, 696)
		ADD_STRUCT(ScriptArray<CoverLink::DynamicLinkInfo>, DynamicLinkInfos, 712)
		ADD_STRUCT(float, InvalidateDistance, 736)
		ADD_STRUCT(float, MaxFireLinkDist, 740)
		ADD_STRUCT(Vector, CircularOrigin, 744)
		ADD_STRUCT(float, CircularRadius, 756)
		ADD_STRUCT(float, AlignDist, 760)
		ADD_STRUCT(float, AutoCoverSlotInterval, 764)
		ADD_STRUCT(float, StandHeight, 768)
		ADD_STRUCT(float, MidHeight, 772)
		ADD_STRUCT(Vector, StandingLeanOffset, 776)
		ADD_STRUCT(Vector, CrouchLeanOffset, 788)
		ADD_STRUCT(Vector, PopupOffset, 800)
		ADD_STRUCT(float, SlipDist, 812)
		ADD_STRUCT(float, TurnDist, 816)
		ADD_STRUCT(float, DangerScale, 820)
		ADD_OBJECT(CoverLink, NextCoverLink, 824)
		ADD_STRUCT(CoverLink::ECoverLocationDescription, LocationDescription, 828)
		bool GetFireLinkTargetCoverInfo(int SlotIdx, int FireLinkIdx, CoverLink::CoverInfo& out_Info, CoverLink::EFireLinkID ArrayID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13204);
			byte params[21] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = FireLinkIdx;
			*(CoverLink::CoverInfo*)&params[8] = out_Info;
			*(CoverLink::EFireLinkID*)&params[16] = ArrayID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Info = *(CoverLink::CoverInfo*)&params[8];
			return *(bool*)&params[20];
		}
		byte PackFireLinkInteractionInfo(CoverLink::ECoverType SrcType, CoverLink::ECoverAction SrcAction, CoverLink::ECoverType DestType, CoverLink::ECoverAction DestAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13210);
			byte params[5] = { NULL };
			*(CoverLink::ECoverType*)params = SrcType;
			*(CoverLink::ECoverAction*)&params[1] = SrcAction;
			*(CoverLink::ECoverType*)&params[2] = DestType;
			*(CoverLink::ECoverAction*)&params[3] = DestAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void UnPackFireLinkInteractionInfo(byte PackedByte, CoverLink::ECoverType& SrcType, CoverLink::ECoverAction& SrcAction, CoverLink::ECoverType& DestType, CoverLink::ECoverAction& DestAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13216);
			byte params[5] = { NULL };
			*params = PackedByte;
			*(CoverLink::ECoverType*)&params[1] = SrcType;
			*(CoverLink::ECoverAction*)&params[2] = SrcAction;
			*(CoverLink::ECoverType*)&params[3] = DestType;
			*(CoverLink::ECoverAction*)&params[4] = DestAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SrcType = *(CoverLink::ECoverType*)&params[1];
			SrcAction = *(CoverLink::ECoverAction*)&params[2];
			DestType = *(CoverLink::ECoverType*)&params[3];
			DestAction = *(CoverLink::ECoverAction*)&params[4];
		}
		Vector GetSlotLocation(int SlotIdx, bool bForceUseOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13222);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bForceUseOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		Rotator GetSlotRotation(int SlotIdx, bool bForceUseOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13226);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bForceUseOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[8];
		}
		Vector GetSlotViewPoint(int SlotIdx, CoverLink::ECoverType Type, CoverLink::ECoverAction Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13230);
			byte params[18] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink::ECoverType*)&params[4] = Type;
			*(CoverLink::ECoverAction*)&params[5] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		bool IsExposedTo(int SlotIdx, CoverLink::CoverInfo ChkSlot, float& out_ExposedScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13235);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink::CoverInfo*)&params[4] = ChkSlot;
			*(float*)&params[12] = out_ExposedScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ExposedScale = *(float*)&params[12];
			return *(bool*)&params[16];
		}
		void SetInvalidUntil(int SlotIdx, float TimeToBecomeValid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13240);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(float*)&params[4] = TimeToBecomeValid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Claim(class Pawn* NewClaim, int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13244);
			byte params[12] = { NULL };
			*(class Pawn**)params = NewClaim;
			*(int*)&params[4] = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnClaim(class Pawn* OldClaim, int SlotIdx, bool bUnclaimAll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13255);
			byte params[16] = { NULL };
			*(class Pawn**)params = OldClaim;
			*(int*)&params[4] = SlotIdx;
			*(bool*)&params[8] = bUnclaimAll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsValidClaim(class Pawn* ChkClaim, int SlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13263);
			byte params[20] = { NULL };
			*(class Pawn**)params = ChkClaim;
			*(int*)&params[4] = SlotIdx;
			*(bool*)&params[8] = bSkipTeamCheck;
			*(bool*)&params[12] = bSkipOverlapCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsValidClaimBetween(class Pawn* ChkClaim, int StartSlotIdx, int EndSlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13269);
			byte params[24] = { NULL };
			*(class Pawn**)params = ChkClaim;
			*(int*)&params[4] = StartSlotIdx;
			*(int*)&params[8] = EndSlotIdx;
			*(bool*)&params[12] = bSkipTeamCheck;
			*(bool*)&params[16] = bSkipOverlapCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool IsStationarySlot(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13276);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13280);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool FindSlots(Vector CheckLocation, float MaxDistance, int& LeftSlotIdx, int& RightSlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13281);
			byte params[28] = { NULL };
			*(Vector*)params = CheckLocation;
			*(float*)&params[12] = MaxDistance;
			*(int*)&params[16] = LeftSlotIdx;
			*(int*)&params[20] = RightSlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LeftSlotIdx = *(int*)&params[16];
			RightSlotIdx = *(int*)&params[20];
			return *(bool*)&params[24];
		}
		bool IsLeftEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13290);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsRightEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13294);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetSlotIdxToLeft(int SlotIdx, int Cnt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13298);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = Cnt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetSlotIdxToRight(int SlotIdx, int Cnt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13302);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = Cnt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool AllowRightTransition(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13306);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowLeftTransition(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13310);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetFireLinkTo(int SlotIdx, CoverLink::CoverInfo ChkCover, CoverLink::ECoverAction ChkAction, CoverLink::ECoverType ChkType, int& out_FireLinkIdx, ScriptArray<int>& out_Items)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13314);
			byte params[34] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink::CoverInfo*)&params[4] = ChkCover;
			*(CoverLink::ECoverAction*)&params[12] = ChkAction;
			*(CoverLink::ECoverType*)&params[13] = ChkType;
			*(int*)&params[16] = out_FireLinkIdx;
			*(ScriptArray<int>*)&params[20] = out_Items;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_FireLinkIdx = *(int*)&params[16];
			out_Items = *(ScriptArray<int>*)&params[20];
			return *(bool*)&params[32];
		}
		bool HasFireLinkTo(int SlotIdx, CoverLink::CoverInfo ChkCover, bool bAllowFallbackLinks)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13323);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(CoverLink::CoverInfo*)&params[4] = ChkCover;
			*(bool*)&params[12] = bAllowFallbackLinks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void GetSlotActions(int SlotIdx, ScriptArray<CoverLink::ECoverAction>& Actions)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13328);
			byte params[16] = { NULL };
			*(int*)params = SlotIdx;
			*(ScriptArray<CoverLink::ECoverAction>*)&params[4] = Actions;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actions = *(ScriptArray<CoverLink::ECoverAction>*)&params[4];
		}
		void SetDisabled(bool bNewDisabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13332);
			byte params[4] = { NULL };
			*(bool*)params = bNewDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSlotEnabled(int SlotIdx, bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13339);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifySlotOwnerCoverDisabled(int SlotIdx, bool bAIOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13342);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bAIOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSlotPlayerOnly(int SlotIdx, bool bInPlayerOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13347);
			byte params[8] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bInPlayerOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnModifyCover(class SeqAct_ModifyCover* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13350);
			byte params[4] = { NULL };
			*(class SeqAct_ModifyCover**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AutoAdjustSlot(int SlotIdx, bool bOnlyCheckLeans)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13358);
			byte params[12] = { NULL };
			*(int*)params = SlotIdx;
			*(bool*)&params[4] = bOnlyCheckLeans;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsEnabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13364);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13366);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateCheckpointRecord(NavigationPoint::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13369);
			byte params[4] = { NULL };
			*(NavigationPoint::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(NavigationPoint::CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(NavigationPoint::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13371);
			byte params[4] = { NULL };
			*(NavigationPoint::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(NavigationPoint::CheckpointRecord*)params;
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13374);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetSwatTurnTarget(int SlotIdx, int Direction, CoverLink::CoverInfo& out_Info)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13375);
			byte params[20] = { NULL };
			*(int*)params = SlotIdx;
			*(int*)&params[4] = Direction;
			*(CoverLink::CoverInfo*)&params[8] = out_Info;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Info = *(CoverLink::CoverInfo*)&params[8];
			return *(bool*)&params[16];
		}
		void BreakFracturedMeshes(Vector Origin, float Radius, float RBStrength, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13380);
			byte params[24] = { NULL };
			*(Vector*)params = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = RBStrength;
			*(ScriptClass**)&params[20] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddCoverSlot(Vector SlotLocation, Rotator SlotRotation, int SlotIdx, bool bForceSlotUpdate, class Scout* Scout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13392);
			byte params[40] = { NULL };
			*(Vector*)params = SlotLocation;
			*(Rotator*)&params[12] = SlotRotation;
			*(int*)&params[24] = SlotIdx;
			*(bool*)&params[28] = bForceSlotUpdate;
			*(class Scout**)&params[32] = Scout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[36];
		}
		ScriptString* GetDebugString(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13399);
			byte params[16] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		CoverLink::ECoverLocationDescription GetLocationDescription(int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13402);
			byte params[5] = { NULL };
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(CoverLink::ECoverLocationDescription*)&params[4];
		}
		ScriptString* GetDebugAbbrev()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13405);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
	const float CoverLink::COVERLINK_DangerDist = 1536.f;
	const float CoverLink::COVERLINK_EdgeExposureDot = 0.85f;
	const float CoverLink::COVERLINK_EdgeCheckDot = 0.25f;
	const float CoverLink::COVERLINK_ExposureDot = 0.4f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
