#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSkelControl_TurretConstrained." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSkelControl_TurretConstrained." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSkelControl_TurretConstrained." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_TurretConstrained : public SkelControlSingleBone
	{
	public:
			void OnTurretStatusChange( bool bIsMoving )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKSkelControl_TurretConstrained.OnTurretStatusChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bIsMoving;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_STRUCT( ::RotatorProperty, ConstrainedBoneRotation, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AssociatedSeatIndex, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, DesiredBoneRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchSpeedScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LagDegreesPerSecond, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsInMotion, 0x100 )
			ADD_VAR( ::BoolProperty, bResetWhenUnattended, 0x80 )
			ADD_VAR( ::BoolProperty, bFixedWhenFiring, 0x40 )
			ADD_VAR( ::BoolProperty, bInvertRoll, 0x20 )
			ADD_VAR( ::BoolProperty, bInvertYaw, 0x10 )
			ADD_VAR( ::BoolProperty, bInvertPitch, 0x8 )
			ADD_VAR( ::BoolProperty, bConstrainRoll, 0x4 )
			ADD_VAR( ::BoolProperty, bConstrainYaw, 0x2 )
			ADD_VAR( ::BoolProperty, bConstrainPitch, 0x1 )
			void InitTurret( Rotator InitRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKSkelControl_TurretConstrained.InitTurret" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = InitRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WouldConstrainPitch( int TestPitch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKSkelControl_TurretConstrained.WouldConstrainPitch" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = TestPitch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
