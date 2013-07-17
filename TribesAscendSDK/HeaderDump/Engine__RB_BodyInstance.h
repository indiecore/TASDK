#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_BodyInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_BodyInstance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_BodyInstance." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_BodyInstance : public Object
	{
	public:
			bool IsFixed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.IsFixed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFixed( bool bNewFixed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.SetFixed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewFixed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetBodyMass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.GetBodyMass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, InstanceDampingScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InstanceMassScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ContactReportForceThreshold, 0xFFFFFFFF )
			ADD_OBJECT( PhysicalMaterial, PhysMaterialOverride )
			ADD_VAR( ::FloatProperty, LastEffectPlayedTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CustomGravityFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OverextensionThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneAngularDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneAngularSpring, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneLinearDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneLinearSpring, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInstanceAlwaysFullAnimWeight, 0x800 )
			ADD_VAR( ::BoolProperty, bForceUnfixed, 0x400 )
			ADD_VAR( ::BoolProperty, bPushBody, 0x200 )
			ADD_VAR( ::BoolProperty, bEnableCollisionResponse, 0x100 )
			ADD_VAR( ::BoolProperty, bOnlyCollideWithPawns, 0x80 )
			ADD_VAR( ::BoolProperty, bMakeSpringToBaseCollisionComponent, 0x40 )
			ADD_VAR( ::BoolProperty, bUseKinActorForBoneSpring, 0x20 )
			ADD_VAR( ::BoolProperty, bTeleportOnOverextension, 0x10 )
			ADD_VAR( ::BoolProperty, bNotifyOwnerOnOverextension, 0x8 )
			ADD_VAR( ::BoolProperty, bDisableOnOverextension, 0x4 )
			ADD_VAR( ::BoolProperty, bEnableBoneSpringAngular, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableBoneSpringLinear, 0x1 )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreviousVelocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Velocity, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BodyIndex, 0xFFFFFFFF )
			bool IsValidBodyInstance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.IsValidBodyInstance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class PhysicsAssetInstance* GetPhysicsAssetInstance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.GetPhysicsAssetInstance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PhysicsAssetInstance** )( params + function->return_val_offset() );
			}

			void* GetUnrealWorldTM(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.GetUnrealWorldTM" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Vector GetUnrealWorldVelocity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.GetUnrealWorldVelocity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetUnrealWorldAngularVelocity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.GetUnrealWorldAngularVelocity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetUnrealWorldVelocityAtPoint( Vector Point )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.GetUnrealWorldVelocityAtPoint" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Point;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void EnableBoneSpring( bool bInEnableLinear, bool bInEnableAngular, void* &InBoneTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.EnableBoneSpring" );
				byte *params = ( byte* )( malloc( 72 ) );
				*( bool* )( params + 0 ) = bInEnableLinear;
				*( bool* )( params + 4 ) = bInEnableAngular;
				*( void** )( params + 16 ) = InBoneTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InBoneTarget = *( void** )( params + 16 );
			}

			void SetBoneSpringParams( float InLinearSpring, float InLinearDamping, float InAngularSpring, float InAngularDamping )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.SetBoneSpringParams" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )( params + 0 ) = InLinearSpring;
				*( float* )( params + 4 ) = InLinearDamping;
				*( float* )( params + 8 ) = InAngularSpring;
				*( float* )( params + 12 ) = InAngularDamping;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBoneSpringTarget( void* &InBoneTarget, bool bTeleport )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.SetBoneSpringTarget" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( void** )( params + 0 ) = InBoneTarget;
				*( bool* )( params + 64 ) = bTeleport;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InBoneTarget = *( void** )( params + 0 );
			}

			void SetBlockRigidBody( bool bNewBlockRigidBody )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.SetBlockRigidBody" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewBlockRigidBody;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPhysMaterialOverride( class PhysicalMaterial* NewPhysMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.SetPhysMaterialOverride" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicalMaterial** )( params + 0 ) = NewPhysMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableCollisionResponse( bool bEnableResponse )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.EnableCollisionResponse" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnableResponse;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetContactReportForceThreshold( float Threshold )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.SetContactReportForceThreshold" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Threshold;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMassProperties( class RB_BodySetup* Setup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.UpdateMassProperties" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class RB_BodySetup** )( params + 0 ) = Setup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateDampingProperties(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_BodyInstance.UpdateDampingProperties" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
