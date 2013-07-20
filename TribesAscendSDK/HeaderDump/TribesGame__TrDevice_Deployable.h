#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice_Deployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice_Deployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice_Deployable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_Deployable : public TrDevice
	{
	public:
			int GetAmmoCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.GetAmmoCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool CanAttemptDeploy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.CanAttemptDeploy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_STRUCT( ::RotatorProperty, m_rDesiredPlacementRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vDesiredPlacementLocation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bIgnoreCollisionForPlacement, 0x1 )
			ADD_VAR( ::FloatProperty, m_fOutsideCheckDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOtherDeployableProximityCheck, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vDeployVolumePlacementExtent, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vPlacementExtent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPlacementScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPerPlayerMaxDeployed, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, c_DeployableHologramClass )
			ADD_OBJECT( TrDeployableHologram, c_DeployableHologram )
			void UpdateDeployModeStatus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.UpdateDeployModeStatus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TickInHandWeapon( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.TickInHandWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrDeployable* Deploy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.Deploy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrDeployable** )( params + function->return_val_offset() );
			}

			bool IsValidDeployTerrain( Vector &OutLocation, Rotator &OutRotation, bool VerificationCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.IsValidDeployTerrain" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = OutLocation;
				*( Rotator* )( params + 12 ) = OutRotation;
				*( bool* )( params + 24 ) = VerificationCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutLocation = *( Vector* )params;
				OutRotation = *( Rotator* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsValidDeployVolume( Vector &OutLocation, Rotator &OutRotation, bool VerificationCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.IsValidDeployVolume" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = OutLocation;
				*( Rotator* )( params + 12 ) = OutRotation;
				*( bool* )( params + 24 ) = VerificationCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutLocation = *( Vector* )params;
				OutRotation = *( Rotator* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsValidDeployProximity( Vector DeployLocation, bool VerificationCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.IsValidDeployProximity" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = DeployLocation;
				*( bool* )( params + 12 ) = VerificationCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsValidOutsideCheck( Vector DeployLocation, bool VerificationCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.IsValidOutsideCheck" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = DeployLocation;
				*( bool* )( params + 12 ) = VerificationCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateReplicatedCarriedAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.UpdateReplicatedCarriedAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSwitchToWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.OnSwitchToWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSwitchAwayFromWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.OnSwitchAwayFromWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckInHandWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.CheckInHandWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HolderEnteredVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.HolderEnteredVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResumeInhandWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.ResumeInhandWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TryPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.TryPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetMaxDeployedLimit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.GetMaxDeployedLimit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool IsDeployableOldest( class TrDeployable* OtherDep )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.IsDeployableOldest" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrDeployable** )params = OtherDep;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BelowMaxCountLimit( bool bDestroyOldest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.BelowMaxCountLimit" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDestroyOldest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ConsumeAmmo( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.ConsumeAmmo" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int AddCarriedAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.AddCarriedAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int AddAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.AddAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void EnterDeployMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.EnterDeployMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ExitDeployMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.ExitDeployMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachWeaponTo( ScriptName SocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.AttachWeaponTo" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 4 ) = SocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndZoom( class UTPlayerController* PC, bool bReturningTo3P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.EndZoom" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )params = PC;
				*( bool* )( params + 4 ) = bReturningTo3P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeVisibility( bool bIsVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.ChangeVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIsVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnterDeployModeDisplay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.EnterDeployModeDisplay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ExitDeployModeDisplay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.ExitDeployModeDisplay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsValidDesiredDeploy( Vector DesiredPlacement, Rotator DesiredRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.IsValidDesiredDeploy" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = DesiredPlacement;
				*( Rotator* )( params + 12 ) = DesiredRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerRequestDeploy( Vector DesiredPlacement, Rotator DesiredRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.ServerRequestDeploy" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = DesiredPlacement;
				*( Rotator* )( params + 12 ) = DesiredRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CustomFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.CustomFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanAutoDeviceFireNow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.CanAutoDeviceFireNow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasAnyAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.HasAnyAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasAmmo( byte FireModeNum, int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Deployable.HasAmmo" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = FireModeNum;
				*( int* )( params + 4 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
