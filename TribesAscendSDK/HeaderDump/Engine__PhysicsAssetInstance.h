#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PhysicsAssetInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PhysicsAssetInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PhysicsAssetInstance." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PhysicsAssetInstance : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bInitBodies, 0x1 )
			ADD_VAR( ::FloatProperty, AngularForceLimitScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularDampingScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularSpringScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearForceLimitScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDampingScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearSpringScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RootBodyIndex, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Owner )
			void SetLinearDriveScale( float InLinearSpringScale, float InLinearDampingScale, float InLinearForceLimitScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetLinearDriveScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = InLinearSpringScale;
				*( float* )( params + 4 ) = InLinearDampingScale;
				*( float* )( params + 8 ) = InLinearForceLimitScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAngularDriveScale( float InAngularSpringScale, float InAngularDampingScale, float InAngularForceLimitScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetAngularDriveScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = InAngularSpringScale;
				*( float* )( params + 4 ) = InAngularDampingScale;
				*( float* )( params + 8 ) = InAngularForceLimitScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetTotalMassBelowBone( ScriptName InBoneName, class PhysicsAsset* InAsset, class SkeletalMesh* InSkelMesh )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.GetTotalMassBelowBone" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = InBoneName;
				*( class PhysicsAsset** )( params + 8 ) = InAsset;
				*( class SkeletalMesh** )( params + 12 ) = InSkelMesh;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetAllBodiesFixed( bool bNewFixed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetAllBodiesFixed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewFixed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetNamedBodiesFixed( bool bNewFixed, bool bSetOtherBodiesToComplement, bool bSkipFullAnimWeightBodies )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetNamedBodiesFixed" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( bool* )params = bNewFixed;
				*( bool* )( params + 20 ) = bSetOtherBodiesToComplement;
				*( bool* )( params + 24 ) = bSkipFullAnimWeightBodies;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceAllBodiesBelowUnfixed( ScriptName &InBoneName, class PhysicsAsset* InAsset, bool InbInstanceAlwaysFullAnimWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.ForceAllBodiesBelowUnfixed" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = InBoneName;
				*( class PhysicsAsset** )( params + 8 ) = InAsset;
				*( bool* )( params + 16 ) = InbInstanceAlwaysFullAnimWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InBoneName = *( ScriptName* )params;
			}

			void SetAllMotorsAngularPositionDrive( bool bEnableSwingDrive, bool bEnableTwistDrive, bool bSkipFullAnimWeightBodies )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetAllMotorsAngularPositionDrive" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bEnableSwingDrive;
				*( bool* )( params + 4 ) = bEnableTwistDrive;
				*( bool* )( params + 12 ) = bSkipFullAnimWeightBodies;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAllMotorsAngularVelocityDrive( bool bEnableSwingDrive, bool bEnableTwistDrive, bool bSkipFullAnimWeightBodies )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetAllMotorsAngularVelocityDrive" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bEnableSwingDrive;
				*( bool* )( params + 4 ) = bEnableTwistDrive;
				*( bool* )( params + 12 ) = bSkipFullAnimWeightBodies;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAllMotorsAngularDriveParams( float InSpring, float InDamping, float InForceLimit, bool bSkipFullAnimWeightBodies )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetAllMotorsAngularDriveParams" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )params = InSpring;
				*( float* )( params + 4 ) = InDamping;
				*( float* )( params + 8 ) = InForceLimit;
				*( bool* )( params + 16 ) = bSkipFullAnimWeightBodies;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetNamedMotorsAngularPositionDrive( bool bEnableSwingDrive, bool bEnableTwistDrive, bool bSetOtherBodiesToComplement )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetNamedMotorsAngularPositionDrive" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( bool* )params = bEnableSwingDrive;
				*( bool* )( params + 4 ) = bEnableTwistDrive;
				*( bool* )( params + 24 ) = bSetOtherBodiesToComplement;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetNamedMotorsAngularVelocityDrive( bool bEnableSwingDrive, bool bEnableTwistDrive, bool bSetOtherBodiesToComplement )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetNamedMotorsAngularVelocityDrive" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( bool* )params = bEnableSwingDrive;
				*( bool* )( params + 4 ) = bEnableTwistDrive;
				*( bool* )( params + 24 ) = bSetOtherBodiesToComplement;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetNamedRBBoneSprings( bool bEnable, float InBoneLinearSpring, float InBoneAngularSpring )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetNamedRBBoneSprings" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( bool* )params = bEnable;
				*( float* )( params + 16 ) = InBoneLinearSpring;
				*( float* )( params + 20 ) = InBoneAngularSpring;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetNamedBodiesBlockRigidBody( bool bNewBlockRigidBody )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetNamedBodiesBlockRigidBody" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( bool* )params = bNewBlockRigidBody;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFullAnimWeightBlockRigidBody( bool bNewBlockRigidBody )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetFullAnimWeightBlockRigidBody" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bNewBlockRigidBody;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFullAnimWeightBonesFixed( bool bNewFixed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.SetFullAnimWeightBonesFixed" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bNewFixed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class RB_BodyInstance* FindBodyInstance( ScriptName BodyName, class PhysicsAsset* InAsset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.FindBodyInstance" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = BodyName;
				*( class PhysicsAsset** )( params + 8 ) = InAsset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class RB_BodyInstance** )( params + function->return_val_offset() );
			}

			class RB_ConstraintInstance* FindConstraintInstance( ScriptName ConName, class PhysicsAsset* InAsset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsAssetInstance.FindConstraintInstance" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ConName;
				*( class PhysicsAsset** )( params + 8 ) = InAsset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class RB_ConstraintInstance** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
