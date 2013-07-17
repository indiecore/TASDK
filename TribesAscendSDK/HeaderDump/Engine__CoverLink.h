#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CoverLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CoverLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CoverLink." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CoverLink : public NavigationPoint
	{
	public:
			bool GetFireLinkTargetCoverInfo( int SlotIdx, int FireLinkIdx, void* &out_Info, byte ArrayID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetFireLinkTargetCoverInfo" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( int* )( params + 4 ) = FireLinkIdx;
				*( void** )( params + 8 ) = out_Info;
				*( byte* )( params + 16 ) = ArrayID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Info = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte PackFireLinkInteractionInfo( byte SrcType, byte SrcAction, byte DestType, byte DestAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.PackFireLinkInteractionInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( byte* )( params + 0 ) = SrcType;
				*( byte* )( params + 1 ) = SrcAction;
				*( byte* )( params + 2 ) = DestType;
				*( byte* )( params + 3 ) = DestAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void UnPackFireLinkInteractionInfo( byte PackedByte, byte &SrcType, byte &SrcAction, byte &DestType, byte &DestAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.UnPackFireLinkInteractionInfo" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = PackedByte;
				*( byte* )( params + 1 ) = SrcType;
				*( byte* )( params + 2 ) = SrcAction;
				*( byte* )( params + 3 ) = DestType;
				*( byte* )( params + 4 ) = DestAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SrcType = *( byte* )( params + 1 );
				SrcAction = *( byte* )( params + 2 );
				DestType = *( byte* )( params + 3 );
				DestAction = *( byte* )( params + 4 );
			}

			Vector GetSlotLocation( int SlotIdx, bool bForceUseOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetSlotLocation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bForceUseOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Rotator GetSlotRotation( int SlotIdx, bool bForceUseOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetSlotRotation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bForceUseOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Vector GetSlotViewPoint( int SlotIdx, byte Type, byte Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetSlotViewPoint" );
				byte *params = ( byte* )( malloc( 6 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( byte* )( params + 4 ) = Type;
				*( byte* )( params + 5 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool IsExposedTo( int SlotIdx, void* ChkSlot, float &out_ExposedScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsExposedTo" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( void** )( params + 4 ) = ChkSlot;
				*( float* )( params + 12 ) = out_ExposedScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ExposedScale = *( float* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetInvalidUntil( int SlotIdx, float TimeToBecomeValid )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.SetInvalidUntil" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( float* )( params + 4 ) = TimeToBecomeValid;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Claim( class Pawn* NewClaim, int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.Claim" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = NewClaim;
				*( int* )( params + 4 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bClaimAllSlots, 0x4 )
			bool UnClaim( class Pawn* OldClaim, int SlotIdx, bool bUnclaimAll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.UnClaim" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Pawn** )( params + 0 ) = OldClaim;
				*( int* )( params + 4 ) = SlotIdx;
				*( bool* )( params + 8 ) = bUnclaimAll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsValidClaim( class Pawn* ChkClaim, int SlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsValidClaim" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Pawn** )( params + 0 ) = ChkClaim;
				*( int* )( params + 4 ) = SlotIdx;
				*( bool* )( params + 8 ) = bSkipTeamCheck;
				*( bool* )( params + 12 ) = bSkipOverlapCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsValidClaimBetween( class Pawn* ChkClaim, int StartSlotIdx, int EndSlotIdx, bool bSkipTeamCheck, bool bSkipOverlapCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsValidClaimBetween" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )( params + 0 ) = ChkClaim;
				*( int* )( params + 4 ) = StartSlotIdx;
				*( int* )( params + 8 ) = EndSlotIdx;
				*( bool* )( params + 12 ) = bSkipTeamCheck;
				*( bool* )( params + 16 ) = bSkipOverlapCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsStationarySlot( int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsStationarySlot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bCircular, 0x20 )
			bool IsEdgeSlot( int SlotIdx, bool bIgnoreLeans )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsEdgeSlot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bIgnoreLeans;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindSlots( Vector CheckLocation, float MaxDistance, int &LeftSlotIdx, int &RightSlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.FindSlots" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = CheckLocation;
				*( float* )( params + 12 ) = MaxDistance;
				*( int* )( params + 16 ) = LeftSlotIdx;
				*( int* )( params + 20 ) = RightSlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				LeftSlotIdx = *( int* )( params + 16 );
				RightSlotIdx = *( int* )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsLeftEdgeSlot( int SlotIdx, bool bIgnoreLeans )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsLeftEdgeSlot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bIgnoreLeans;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsRightEdgeSlot( int SlotIdx, bool bIgnoreLeans )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsRightEdgeSlot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bIgnoreLeans;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetSlotIdxToLeft( int SlotIdx, int Cnt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetSlotIdxToLeft" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( int* )( params + 4 ) = Cnt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetSlotIdxToRight( int SlotIdx, int Cnt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetSlotIdxToRight" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( int* )( params + 4 ) = Cnt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool AllowRightTransition( int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.AllowRightTransition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowLeftTransition( int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.AllowLeftTransition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetFireLinkTo( int SlotIdx, void* ChkCover, byte ChkAction, byte ChkType, int &out_FireLinkIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetFireLinkTo" );
				byte *params = ( byte* )( malloc( 30 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( void** )( params + 4 ) = ChkCover;
				*( byte* )( params + 12 ) = ChkAction;
				*( byte* )( params + 13 ) = ChkType;
				*( int* )( params + 16 ) = out_FireLinkIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_FireLinkIdx = *( int* )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasFireLinkTo( int SlotIdx, void* ChkCover, bool bAllowFallbackLinks )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.HasFireLinkTo" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( void** )( params + 4 ) = ChkCover;
				*( bool* )( params + 12 ) = bAllowFallbackLinks;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetSlotActions( int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetSlotActions" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDisabled( bool bNewDisabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.SetDisabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewDisabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bDisabled, 0x2 )
			void SetSlotEnabled( int SlotIdx, bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.SetSlotEnabled" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifySlotOwnerCoverDisabled( int SlotIdx, bool bAIOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.NotifySlotOwnerCoverDisabled" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bAIOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSlotPlayerOnly( int SlotIdx, bool bInPlayerOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.SetSlotPlayerOnly" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bInPlayerOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnModifyCover( class SeqAct_ModifyCover* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.OnModifyCover" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ModifyCover** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AutoAdjustSlot( int SlotIdx, bool bOnlyCheckLeans )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.AutoAdjustSlot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( bool* )( params + 4 ) = bOnlyCheckLeans;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsEnabled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.IsEnabled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnToggle( class SeqAct_Toggle* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetSwatTurnTarget( int SlotIdx, int Direction, void* &out_Info )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetSwatTurnTarget" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = SlotIdx;
				*( int* )( params + 4 ) = Direction;
				*( void** )( params + 8 ) = out_Info;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Info = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BreakFracturedMeshes( Vector Origin, float Radius, float RBStrength, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.BreakFracturedMeshes" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = Origin;
				*( float* )( params + 12 ) = Radius;
				*( float* )( params + 16 ) = RBStrength;
				*( ScriptClass** )( params + 20 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bFractureOnTouch, 0x200 )
			int AddCoverSlot( Vector SlotLocation, Rotator SlotRotation, int SlotIdx, bool bForceSlotUpdate, class Scout* Scout )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.AddCoverSlot" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )( params + 0 ) = SlotLocation;
				*( Rotator* )( params + 12 ) = SlotRotation;
				*( int* )( params + 24 ) = SlotIdx;
				*( bool* )( params + 28 ) = bForceSlotUpdate;
				*( class Scout** )( params + 32 ) = Scout;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetDebugString( int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetDebugString" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			byte GetLocationDescription( int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetLocationDescription" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetDebugAbbrev(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverLink.GetDebugAbbrev" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, GLOBAL_bUseSlotMarkers, 0x1 )
			ADD_VAR( ::BoolProperty, bAutoSort, 0x8 )
			ADD_VAR( ::BoolProperty, bAutoAdjust, 0x10 )
			ADD_VAR( ::BoolProperty, bLooped, 0x40 )
			ADD_VAR( ::BoolProperty, bPlayerOnly, 0x80 )
			ADD_VAR( ::BoolProperty, bDynamicCover, 0x100 )
			ADD_VAR( ::BoolProperty, bDebug_FireLinks, 0x400 )
			ADD_VAR( ::BoolProperty, bDebug_ExposedLinks, 0x800 )
			ADD_VAR( ::BoolProperty, bDebug_CoverGen, 0x1000 )
			ADD_VAR( ::BoolProperty, bDoAutoSlotDensityFixup, 0x2000 )
			ADD_VAR( ::FloatProperty, LeanTraceDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InvalidateDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxFireLinkDist, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CircularOrigin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CircularRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AlignDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AutoCoverSlotInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StandHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MidHeight, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StandingLeanOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CrouchLeanOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PopupOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SlipDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DangerScale, 0xFFFFFFFF )
			ADD_OBJECT( CoverLink, NextCoverLink )
			ADD_VAR( ::ByteProperty, LocationDescription, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
