#pragma once
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "Engine__SeqAct_ModifyCover.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Scout.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CoverLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CoverLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CoverLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CoverLink : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bClaimAllSlots, 0x4)
		ADD_VAR(::BoolProperty, bCircular, 0x20)
		ADD_VAR(::BoolProperty, bDisabled, 0x2)
		ADD_VAR(::BoolProperty, bFractureOnTouch, 0x200)
		ADD_VAR(::BoolProperty, GLOBAL_bUseSlotMarkers, 0x1)
		ADD_VAR(::BoolProperty, bAutoSort, 0x8)
		ADD_VAR(::BoolProperty, bAutoAdjust, 0x10)
		ADD_VAR(::BoolProperty, bLooped, 0x40)
		ADD_VAR(::BoolProperty, bPlayerOnly, 0x80)
		ADD_VAR(::BoolProperty, bDynamicCover, 0x100)
		ADD_VAR(::BoolProperty, bDebug_FireLinks, 0x400)
		ADD_VAR(::BoolProperty, bDebug_ExposedLinks, 0x800)
		ADD_VAR(::BoolProperty, bDebug_CoverGen, 0x1000)
		ADD_VAR(::BoolProperty, bDoAutoSlotDensityFixup, 0x2000)
		ADD_VAR(::FloatProperty, LeanTraceDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InvalidateDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxFireLinkDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CircularOrigin, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, CircularRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlignDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoCoverSlotInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StandHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidHeight, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StandingLeanOffset, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, CrouchLeanOffset, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, PopupOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, SlipDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TurnDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DangerScale, 0xFFFFFFFF)
		ADD_OBJECT(CoverLink, NextCoverLink)
		ADD_VAR(::ByteProperty, LocationDescription, 0xFFFFFFFF)
		bool GetFireLinkTargetCoverInfo(int SlotIdx, int FireLinkIdx, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void*& out_Info, byte ArrayID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetFireLinkTargetCoverInfo");
			byte* params = (byte*)malloc(21);
			*(int*)params = SlotIdx;
			*(int*)(params + 4) = FireLinkIdx;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void**)(params + 8) = out_Info;
			*(params + 16) = ArrayID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Info = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		byte PackFireLinkInteractionInfo(byte SrcType, byte SrcAction, byte DestType, byte DestAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.PackFireLinkInteractionInfo");
			byte* params = (byte*)malloc(5);
			*params = SrcType;
			*(params + 1) = SrcAction;
			*(params + 2) = DestType;
			*(params + 3) = DestAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		void UnPackFireLinkInteractionInfo(byte PackedByte, byte& SrcType, byte& SrcAction, byte& DestType, byte& DestAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.UnPackFireLinkInteractionInfo");
			byte* params = (byte*)malloc(5);
			*params = PackedByte;
			*(params + 1) = SrcType;
			*(params + 2) = SrcAction;
			*(params + 3) = DestType;
			*(params + 4) = DestAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SrcType = *(params + 1);
			SrcAction = *(params + 2);
			DestType = *(params + 3);
			DestAction = *(params + 4);
			free(params);
		}
		Vector GetSlotLocation(int SlotIdx, bool bForceUseOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetSlotLocation");
			byte* params = (byte*)malloc(20);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bForceUseOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
		Rotator GetSlotRotation(int SlotIdx, bool bForceUseOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetSlotRotation");
			byte* params = (byte*)malloc(20);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bForceUseOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 8);
			free(params);
			return returnVal;
		}
		Vector GetSlotViewPoint(int SlotIdx, byte Type, byte Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetSlotViewPoint");
			byte* params = (byte*)malloc(18);
			*(int*)params = SlotIdx;
			*(params + 4) = Type;
			*(params + 5) = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsExposedTo(int SlotIdx, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void* ChkSlot, float& out_ExposedScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsExposedTo");
			byte* params = (byte*)malloc(20);
			*(int*)params = SlotIdx;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void**)(params + 4) = ChkSlot;
			*(float*)(params + 12) = out_ExposedScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ExposedScale = *(float*)(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetInvalidUntil(int SlotIdx, float TimeToBecomeValid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.SetInvalidUntil");
			byte* params = (byte*)malloc(8);
			*(int*)params = SlotIdx;
			*(float*)(params + 4) = TimeToBecomeValid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Claim(class Pawn* NewClaim, int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.Claim");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = NewClaim;
			*(int*)(params + 4) = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool UnClaim(class Pawn* OldClaim, int SlotIdx, bool bUnclaimAll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.UnClaim");
			byte* params = (byte*)malloc(16);
			*(class Pawn**)params = OldClaim;
			*(int*)(params + 4) = SlotIdx;
			*(bool*)(params + 8) = bUnclaimAll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool IsValidClaim(class Pawn* ChkClaim, int SlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsValidClaim");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = ChkClaim;
			*(int*)(params + 4) = SlotIdx;
			*(bool*)(params + 8) = bSkipTeamCheck;
			*(bool*)(params + 12) = bSkipOverlapCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsValidClaimBetween(class Pawn* ChkClaim, int StartSlotIdx, int EndSlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsValidClaimBetween");
			byte* params = (byte*)malloc(24);
			*(class Pawn**)params = ChkClaim;
			*(int*)(params + 4) = StartSlotIdx;
			*(int*)(params + 8) = EndSlotIdx;
			*(bool*)(params + 12) = bSkipTeamCheck;
			*(bool*)(params + 16) = bSkipOverlapCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool IsStationarySlot(int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsStationarySlot");
			byte* params = (byte*)malloc(8);
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsEdgeSlot");
			byte* params = (byte*)malloc(12);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool FindSlots(Vector CheckLocation, float MaxDistance, int& LeftSlotIdx, int& RightSlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.FindSlots");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = CheckLocation;
			*(float*)(params + 12) = MaxDistance;
			*(int*)(params + 16) = LeftSlotIdx;
			*(int*)(params + 20) = RightSlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			LeftSlotIdx = *(int*)(params + 16);
			RightSlotIdx = *(int*)(params + 20);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool IsLeftEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsLeftEdgeSlot");
			byte* params = (byte*)malloc(12);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsRightEdgeSlot(int SlotIdx, bool bIgnoreLeans)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsRightEdgeSlot");
			byte* params = (byte*)malloc(12);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bIgnoreLeans;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetSlotIdxToLeft(int SlotIdx, int Cnt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetSlotIdxToLeft");
			byte* params = (byte*)malloc(12);
			*(int*)params = SlotIdx;
			*(int*)(params + 4) = Cnt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetSlotIdxToRight(int SlotIdx, int Cnt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetSlotIdxToRight");
			byte* params = (byte*)malloc(12);
			*(int*)params = SlotIdx;
			*(int*)(params + 4) = Cnt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AllowRightTransition(int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.AllowRightTransition");
			byte* params = (byte*)malloc(8);
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowLeftTransition(int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.AllowLeftTransition");
			byte* params = (byte*)malloc(8);
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetFireLinkTo(int SlotIdx, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void* ChkCover, byte ChkAction, byte ChkType, int& out_FireLinkIdx, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Items)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetFireLinkTo");
			byte* params = (byte*)malloc(34);
			*(int*)params = SlotIdx;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void**)(params + 4) = ChkCover;
			*(params + 12) = ChkAction;
			*(params + 13) = ChkType;
			*(int*)(params + 16) = out_FireLinkIdx;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = out_Items;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_FireLinkIdx = *(int*)(params + 16);
			out_Items = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool HasFireLinkTo(int SlotIdx, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void* ChkCover, bool bAllowFallbackLinks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.HasFireLinkTo");
			byte* params = (byte*)malloc(20);
			*(int*)params = SlotIdx;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void**)(params + 4) = ChkCover;
			*(bool*)(params + 12) = bAllowFallbackLinks;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void GetSlotActions(int SlotIdx, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Actions)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetSlotActions");
			byte* params = (byte*)malloc(16);
			*(int*)params = SlotIdx;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Actions;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Actions = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void SetDisabled(bool bNewDisabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.SetDisabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewDisabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSlotEnabled(int SlotIdx, bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.SetSlotEnabled");
			byte* params = (byte*)malloc(8);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifySlotOwnerCoverDisabled(int SlotIdx, bool bAIOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.NotifySlotOwnerCoverDisabled");
			byte* params = (byte*)malloc(8);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bAIOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSlotPlayerOnly(int SlotIdx, bool bInPlayerOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.SetSlotPlayerOnly");
			byte* params = (byte*)malloc(8);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bInPlayerOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnModifyCover(class SeqAct_ModifyCover* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.OnModifyCover");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ModifyCover**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AutoAdjustSlot(int SlotIdx, bool bOnlyCheckLeans)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.AutoAdjustSlot");
			byte* params = (byte*)malloc(12);
			*(int*)params = SlotIdx;
			*(bool*)(params + 4) = bOnlyCheckLeans;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.IsEnabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetSwatTurnTarget(int SlotIdx, int Direction, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void*& out_Info)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetSwatTurnTarget");
			byte* params = (byte*)malloc(20);
			*(int*)params = SlotIdx;
			*(int*)(params + 4) = Direction;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void**)(params + 8) = out_Info;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Info = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverLink.CoverInfo'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void BreakFracturedMeshes(Vector Origin, float Radius, float RBStrength, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.BreakFracturedMeshes");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Origin;
			*(float*)(params + 12) = Radius;
			*(float*)(params + 16) = RBStrength;
			*(ScriptClass**)(params + 20) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int AddCoverSlot(Vector SlotLocation, Rotator SlotRotation, int SlotIdx, bool bForceSlotUpdate, class Scout* Scout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.AddCoverSlot");
			byte* params = (byte*)malloc(40);
			*(Vector*)params = SlotLocation;
			*(Rotator*)(params + 12) = SlotRotation;
			*(int*)(params + 24) = SlotIdx;
			*(bool*)(params + 28) = bForceSlotUpdate;
			*(class Scout**)(params + 32) = Scout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 36);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetDebugString(int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetDebugString");
			byte* params = (byte*)malloc(16);
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		byte GetLocationDescription(int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetLocationDescription");
			byte* params = (byte*)malloc(5);
			*(int*)params = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetDebugAbbrev()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverLink.GetDebugAbbrev");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
