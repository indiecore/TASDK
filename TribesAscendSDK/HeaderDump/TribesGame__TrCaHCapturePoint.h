#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCaHCapturePoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCaHCapturePoint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCaHCapturePoint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCaHCapturePoint : public TrGameObjective
	{
	public:
			ADD_VAR( ::FloatProperty, m_HoldTheLineAccoladeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fNearbyPawnCheckTime, 0xFFFFFFFF )
			ADD_OBJECT( TrPlayerController, m_LastCapturedBy )
			ADD_VAR( ::FloatProperty, m_fPointPulseMarkerSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPointPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPointPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseMarkerSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPulseMarkerTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_MarkerSize, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nFlashPointPulse, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_CapturePointLabel, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bIsHeld, 0x1 )
			ADD_STRUCT( ::VectorProperty, LastCameraPos, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastCameraDir, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastScreenLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInfluenceRadiusSize, 0xFFFFFFFF )
			ADD_OBJECT( SkelControlSingleBone, m_SkyHologramSkelControl )
			ADD_VAR( ::FloatProperty, m_fSkyHologramScaleDS, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramScaleBE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramScaleOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vSkyHologramOffsetDS, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vSkyHologramOffsetBE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramOffsetZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramOffsetY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSkyHologramOffsetX, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_DiamondSwordHologramMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_BloodEagleHologramMIC )
			ADD_VAR( ::StrProperty, m_sCapturePointName, 0xFFFFFFFF )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PulseMarker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.PulseMarker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PointPulseMarker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.PointPulseMarker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateHologramVisibility(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.UpdateHologramVisibility" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPawnTouched( class TrPawn* TRP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.OnPawnTouched" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )( params + 0 ) = TRP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostCapturePointTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.PostCapturePointTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AwardPointTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.AwardPointTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldPostRenderForCaH(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.ShouldPostRenderForCaH" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetScreenName( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.GetScreenName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckNearbyPlayersTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.CheckNearbyPlayersTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPawnConsideredNearby( class TrPawn* TRP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCaHCapturePoint.IsPawnConsideredNearby" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )( params + 0 ) = TRP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
