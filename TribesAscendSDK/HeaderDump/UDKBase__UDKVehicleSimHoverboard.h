#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKVehicleSimHoverboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKVehicleSimHoverboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKVehicleSimHoverboard." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKVehicleSimHoverboard : public SVehicleSimBase
	{
	public:
			ADD_VAR( ::FloatProperty, CurrentLookYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SlalomSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HoverboardSlalomMaxAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentSteerOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LandedCountdown, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpinSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AutoSpin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpinHeadingOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TrickJumpWarmup, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TakeoffYaw, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, GroundNormal, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, OverWaterSound )
			ADD_VAR( ::FloatProperty, WaterCheckLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StopThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLeftGround, 0x4 )
			ADD_VAR( ::BoolProperty, bInAJump, 0x2 )
			ADD_VAR( ::BoolProperty, bIsOverDeepWater, 0x1 )
			ADD_VAR( ::FloatProperty, MaxTurnTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpinTurnTorqueScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnTorqueFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRiseForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LatDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxStrafeForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LongDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxReverseVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxReverseForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxThrustForce, 0xFFFFFFFF )
			void InitWheels( class UDKVehicle* Vehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicleSimHoverboard.InitWheels" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKVehicle** )( params + 0 ) = Vehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateLeanConstraint( class RB_ConstraintInstance* LeanUprightConstraintInstance, Vector LeanY, Vector LeanZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicleSimHoverboard.UpdateLeanConstraint" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class RB_ConstraintInstance** )( params + 0 ) = LeanUprightConstraintInstance;
				*( Vector* )( params + 4 ) = LeanY;
				*( Vector* )( params + 16 ) = LeanZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
