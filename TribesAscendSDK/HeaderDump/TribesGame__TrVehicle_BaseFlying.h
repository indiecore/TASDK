#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVehicle_BaseFlying." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVehicle_BaseFlying." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVehicle_BaseFlying." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicle_BaseFlying : public TrVehicle
	{
	public:
			ADD_VAR( ::BoolProperty, m_bCanAutoLevelVehicle, 0x2 )
			ADD_VAR( ::BoolProperty, m_bFreeLook, 0x1 )
			ADD_VAR( ::FloatProperty, m_fBoostThrustInvDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostThrustBuildUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fThrustInvDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fThrustBuildUp, 0xFFFFFFFF )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_BaseFlying.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateParticleSystems(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_BaseFlying.CreateParticleSystems" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInputs( float InForward, float InStrafe, float InUp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_BaseFlying.SetInputs" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = InForward;
				*( float* )( params + 4 ) = InStrafe;
				*( float* )( params + 8 ) = InUp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleCalcCamera( float DeltaTime, int SeatIndex, Vector &out_CamLoc, Rotator &out_CamRot, Vector &CamStart, bool bPivotOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_BaseFlying.VehicleCalcCamera" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( int* )( params + 4 ) = SeatIndex;
				*( Vector* )( params + 8 ) = out_CamLoc;
				*( Rotator* )( params + 20 ) = out_CamRot;
				*( Vector* )( params + 32 ) = CamStart;
				*( bool* )( params + 44 ) = bPivotOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 8 );
				out_CamRot = *( Rotator* )( params + 20 );
				CamStart = *( Vector* )( params + 32 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
