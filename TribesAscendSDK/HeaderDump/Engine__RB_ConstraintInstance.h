#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_ConstraintInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_ConstraintInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_ConstraintInstance." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_ConstraintInstance : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bTerminated, 0x1000 )
			ADD_VAR( ::IntProperty, ConstraintIndex, 0xFFFFFFFF )
			void TermConstraint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.TermConstraint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, AngularDriveForceLimit, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularDriveDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularDriveSpring, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, AngularVelocityTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDriveForceLimit, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDriveDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDriveSpring, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LinearVelocityTarget, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LinearPositionTarget, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAngularSlerpDrive, 0x800 )
			ADD_VAR( ::BoolProperty, bTwistVelocityDrive, 0x400 )
			ADD_VAR( ::BoolProperty, bTwistPositionDrive, 0x200 )
			ADD_VAR( ::BoolProperty, bSwingVelocityDrive, 0x100 )
			ADD_VAR( ::BoolProperty, bSwingPositionDrive, 0x80 )
			ADD_VAR( ::BoolProperty, bLinearZVelocityDrive, 0x40 )
			ADD_VAR( ::BoolProperty, bLinearZPositionDrive, 0x20 )
			ADD_VAR( ::BoolProperty, bLinearYVelocityDrive, 0x10 )
			ADD_VAR( ::BoolProperty, bLinearYPositionDrive, 0x8 )
			ADD_VAR( ::BoolProperty, bLinearXVelocityDrive, 0x4 )
			ADD_VAR( ::BoolProperty, bLinearXPositionDrive, 0x2 )
			ADD_VAR( ::BoolProperty, bInHardware, 0x1 )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Owner )
			void InitConstraint( class RB_ConstraintSetup* Setup, float Scale, class Actor* InOwner, bool bMakeKinForBody1 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.InitConstraint" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class RB_ConstraintSetup** )( params + 8 ) = Setup;
				*( float* )( params + 12 ) = Scale;
				*( class Actor** )( params + 16 ) = InOwner;
				*( bool* )( params + 24 ) = bMakeKinForBody1;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PhysicsAssetInstance* GetPhysicsAssetInstance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.GetPhysicsAssetInstance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PhysicsAssetInstance** )( params + function->return_val_offset() );
			}

			Vector GetConstraintLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.GetConstraintLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SetLinearPositionDrive( bool bEnableXDrive, bool bEnableYDrive, bool bEnableZDrive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetLinearPositionDrive" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = bEnableXDrive;
				*( bool* )( params + 4 ) = bEnableYDrive;
				*( bool* )( params + 8 ) = bEnableZDrive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLinearVelocityDrive( bool bEnableXDrive, bool bEnableYDrive, bool bEnableZDrive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetLinearVelocityDrive" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = bEnableXDrive;
				*( bool* )( params + 4 ) = bEnableYDrive;
				*( bool* )( params + 8 ) = bEnableZDrive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAngularPositionDrive( bool bEnableSwingDrive, bool bEnableTwistDrive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetAngularPositionDrive" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bEnableSwingDrive;
				*( bool* )( params + 4 ) = bEnableTwistDrive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAngularVelocityDrive( bool bEnableSwingDrive, bool bEnableTwistDrive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetAngularVelocityDrive" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bEnableSwingDrive;
				*( bool* )( params + 4 ) = bEnableTwistDrive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLinearPositionTarget( Vector InPosTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetLinearPositionTarget" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = InPosTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLinearVelocityTarget( Vector InVelTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetLinearVelocityTarget" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = InVelTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLinearDriveParams( float InSpring, float InDamping, float InForceLimit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetLinearDriveParams" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = InSpring;
				*( float* )( params + 4 ) = InDamping;
				*( float* )( params + 8 ) = InForceLimit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAngularPositionTarget( void* &InPosTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetAngularPositionTarget" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = InPosTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InPosTarget = *( void** )( params + 0 );
			}

			void SetAngularVelocityTarget( Vector InVelTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetAngularVelocityTarget" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = InVelTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAngularDriveParams( float InSpring, float InDamping, float InForceLimit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetAngularDriveParams" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = InSpring;
				*( float* )( params + 4 ) = InDamping;
				*( float* )( params + 8 ) = InForceLimit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAngularDOFLimitScale( float InSwing1LimitScale, float InSwing2LimitScale, float InTwistLimitScale, class RB_ConstraintSetup* InSetup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetAngularDOFLimitScale" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = InSwing1LimitScale;
				*( float* )( params + 4 ) = InSwing2LimitScale;
				*( float* )( params + 8 ) = InTwistLimitScale;
				*( class RB_ConstraintSetup** )( params + 12 ) = InSetup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLinearLimitSize( float NewLimitSize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.SetLinearLimitSize" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = NewLimitSize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveKinActorTransform( void* &NewTM )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintInstance.MoveKinActorTransform" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( void** )( params + 0 ) = NewTM;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewTM = *( void** )( params + 0 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
