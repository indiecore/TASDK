#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkeletalMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkeletalMeshComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkeletalMeshComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkeletalMeshComponent : public MeshComponent
	{
	public:
			void AttachComponent( ScriptName BoneName, Vector RelativeLocation, Rotator RelativeRotation, Vector RelativeScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.AttachComponent" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( ScriptName* )( params + 4 ) = BoneName;
				*( Vector* )( params + 12 ) = RelativeLocation;
				*( Rotator* )( params + 24 ) = RelativeRotation;
				*( Vector* )( params + 36 ) = RelativeScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.DetachComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachComponentToSocket( ScriptName SocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.AttachComponentToSocket" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 4 ) = SocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetSocketWorldLocationAndRotation( ScriptName InSocketName, Vector &OutLocation, Rotator &OutRotation, int Space )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetSocketWorldLocationAndRotation" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )( params + 0 ) = InSocketName;
				*( Vector* )( params + 8 ) = OutLocation;
				*( Rotator* )( params + 20 ) = OutRotation;
				*( int* )( params + 32 ) = Space;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutLocation = *( Vector* )( params + 8 );
				OutRotation = *( Rotator* )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			class SkeletalMeshSocket* GetSocketByName( ScriptName InSocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetSocketByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InSocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMeshSocket** )( params + function->return_val_offset() );
			}

			ScriptName GetSocketBoneName( ScriptName InSocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetSocketBoneName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InSocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void* FindComponentAttachedToBone( ScriptName InBoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindComponentAttachedToBone" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InBoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool IsComponentAttached( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.IsComponentAttached" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 4 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AttachedComponents( ScriptClass* BaseClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.AttachedComponents" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = BaseClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetTransformMatrix(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetTransformMatrix" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void SetSkeletalMesh( class SkeletalMesh* NewMesh, bool bKeepSpaceBases )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetSkeletalMesh" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SkeletalMesh** )( params + 0 ) = NewMesh;
				*( bool* )( params + 4 ) = bKeepSpaceBases;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPhysicsAsset( class PhysicsAsset* NewPhysicsAsset, bool bForceReInit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetPhysicsAsset" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PhysicsAsset** )( params + 0 ) = NewPhysicsAsset;
				*( bool* )( params + 4 ) = bForceReInit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetForceRefPose( bool bNewForceRefPose )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetForceRefPose" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewForceRefPose;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEnableClothSimulation( bool bInEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetEnableClothSimulation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bInEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothFrozen( bool bNewFrozen )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothFrozen" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewFrozen;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEnableClothingSimulation( bool bInEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetEnableClothingSimulation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bInEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateClothParams(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UpdateClothParams" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothExternalForce( Vector InForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothExternalForce" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = InForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAttachClothVertsToBaseBody( bool bAttachVerts )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetAttachClothVertsToBaseBody" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bAttachVerts;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetClothVertsToRefPose(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.ResetClothVertsToRefPose" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetClothAttachmentResponseCoefficient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothAttachmentResponseCoefficient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothAttachmentTearFactor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothAttachmentTearFactor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothBendingStiffness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothBendingStiffness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothCollisionResponseCoefficient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothCollisionResponseCoefficient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothDampingCoefficient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothDampingCoefficient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int GetClothFlags(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothFlags" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float GetClothFriction(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothFriction" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothPressure(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothPressure" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothSleepLinearVelocity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothSleepLinearVelocity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int GetClothSolverIterations(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothSolverIterations" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float GetClothStretchingStiffness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothStretchingStiffness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothTearFactor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothTearFactor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetClothThickness(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClothThickness" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetClothAttachmentResponseCoefficient( float ClothAttachmentResponseCoefficient )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothAttachmentResponseCoefficient" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothAttachmentResponseCoefficient;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothAttachmentTearFactor( float ClothAttachTearFactor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothAttachmentTearFactor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothAttachTearFactor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothBendingStiffness( float ClothBendingStiffness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothBendingStiffness" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothBendingStiffness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothCollisionResponseCoefficient( float ClothCollisionResponseCoefficient )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothCollisionResponseCoefficient" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothCollisionResponseCoefficient;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothDampingCoefficient( float ClothDampingCoefficient )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothDampingCoefficient" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothDampingCoefficient;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothFlags( int ClothFlags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothFlags" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ClothFlags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothFriction( float ClothFriction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothFriction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothFriction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothPressure( float ClothPressure )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothPressure" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothPressure;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothSleepLinearVelocity( float ClothSleepLinearVelocity )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothSleepLinearVelocity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothSleepLinearVelocity;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothSolverIterations( int ClothSolverIterations )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothSolverIterations" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ClothSolverIterations;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothStretchingStiffness( float ClothStretchingStiffness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothStretchingStiffness" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothStretchingStiffness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothTearFactor( float ClothTearFactor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothTearFactor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothTearFactor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothThickness( float ClothThickness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothThickness" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ClothThickness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothSleep( bool IfClothSleep )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothSleep" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = IfClothSleep;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothPosition( Vector ClothOffSet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothPosition" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = ClothOffSet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothVelocity( Vector VelocityOffSet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothVelocity" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = VelocityOffSet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachClothToCollidingShapes( bool AttatchTwoWay, bool AttachTearable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.AttachClothToCollidingShapes" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = AttatchTwoWay;
				*( bool* )( params + 4 ) = AttachTearable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableClothValidBounds( bool IfEnableClothValidBounds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.EnableClothValidBounds" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = IfEnableClothValidBounds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClothValidBounds( Vector ClothValidBoundsMin, Vector ClothValidBoundsMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetClothValidBounds" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = ClothValidBoundsMin;
				*( Vector* )( params + 12 ) = ClothValidBoundsMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSoftBodyParams(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UpdateSoftBodyParams" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSoftBodyFrozen( bool bNewFrozen )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetSoftBodyFrozen" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewFrozen;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WakeSoftBody(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.WakeSoftBody" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class AnimSequence* FindAnimSequence( ScriptName AnimSeqName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindAnimSequence" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = AnimSeqName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimSequence** )( params + function->return_val_offset() );
			}

			void SaveAnimSets(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SaveAnimSets" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RestoreSavedAnimSets(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.RestoreSavedAnimSets" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetAnimRateByDuration( ScriptName AnimSeqName, float Duration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetAnimRateByDuration" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = AnimSeqName;
				*( float* )( params + 8 ) = Duration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetAnimLength( ScriptName AnimSeqName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetAnimLength" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = AnimSeqName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class MorphTarget* FindMorphTarget( ScriptName MorphTargetName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindMorphTarget" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = MorphTargetName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MorphTarget** )( params + function->return_val_offset() );
			}

			class AnimNode* FindAnimNode( ScriptName InNodeName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindAnimNode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InNodeName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNode** )( params + function->return_val_offset() );
			}

			void AllAnimNodes( ScriptClass* BaseClass, class AnimNode* &Node )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.AllAnimNodes" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = BaseClass;
				*( class AnimNode** )( params + 4 ) = Node;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Node = *( class AnimNode** )( params + 4 );
			}

			class SkelControlBase* FindSkelControl( ScriptName InControlName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindSkelControl" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InControlName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkelControlBase** )( params + function->return_val_offset() );
			}

			class MorphNodeBase* FindMorphNode( ScriptName InNodeName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindMorphNode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InNodeName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MorphNodeBase** )( params + function->return_val_offset() );
			}

			void* GetBoneQuaternion( ScriptName BoneName, int Space )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetBoneQuaternion" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( int* )( params + 8 ) = Space;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			Vector GetBoneLocation( ScriptName BoneName, int Space )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetBoneLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( int* )( params + 8 ) = Space;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			int MatchRefBone( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.MatchRefBone" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptName GetBoneName( int BoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetBoneName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = BoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void* GetBoneMatrix( int BoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetBoneMatrix" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = BoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ScriptName GetParentBone( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetParentBone" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void GetBoneNames(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetBoneNames" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool BoneIsChildOf( ScriptName BoneName, ScriptName ParentBoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.BoneIsChildOf" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( ScriptName* )( params + 8 ) = ParentBoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GetRefPosePosition( int BoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetRefPosePosition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = BoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetBoneAxis( ScriptName BoneName, byte Axis )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetBoneAxis" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( byte* )( params + 8 ) = Axis;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void TransformToBoneSpace( ScriptName BoneName, Vector InPosition, Rotator InRotation, Vector &OutPosition, Rotator &OutRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.TransformToBoneSpace" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( Vector* )( params + 8 ) = InPosition;
				*( Rotator* )( params + 20 ) = InRotation;
				*( Vector* )( params + 32 ) = OutPosition;
				*( Rotator* )( params + 44 ) = OutRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutPosition = *( Vector* )( params + 32 );
				OutRotation = *( Rotator* )( params + 44 );
			}

			void TransformFromBoneSpace( ScriptName BoneName, Vector InPosition, Rotator InRotation, Vector &OutPosition, Rotator &OutRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.TransformFromBoneSpace" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( Vector* )( params + 8 ) = InPosition;
				*( Rotator* )( params + 20 ) = InRotation;
				*( Vector* )( params + 32 ) = OutPosition;
				*( Rotator* )( params + 44 ) = OutRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutPosition = *( Vector* )( params + 32 );
				OutRotation = *( Rotator* )( params + 44 );
			}

			ScriptName FindClosestBone( Vector TestLocation, Vector &BoneLocation, float IgnoreScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindClosestBone" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )( params + 0 ) = TestLocation;
				*( Vector* )( params + 12 ) = BoneLocation;
				*( float* )( params + 24 ) = IgnoreScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BoneLocation = *( Vector* )( params + 12 );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			Vector GetClosestCollidingBoneLocation( Vector TestLocation, bool bCheckZeroExtent, bool bCheckNonZeroExtent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetClosestCollidingBoneLocation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = TestLocation;
				*( bool* )( params + 12 ) = bCheckZeroExtent;
				*( bool* )( params + 16 ) = bCheckNonZeroExtent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SetAnimTreeTemplate( class AnimTree* NewTemplate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetAnimTreeTemplate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimTree** )( params + 0 ) = NewTemplate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetParentAnimComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetParentAnimComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateParentBoneMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UpdateParentBoneMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitSkelControls(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.InitSkelControls" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitMorphTargets(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.InitMorphTargets" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindConstraintIndex( ScriptName ConstraintName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindConstraintIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ConstraintName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptName FindConstraintBoneName( int ConstraintIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindConstraintBoneName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ConstraintIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			class RB_BodyInstance* FindBodyInstanceNamed( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindBodyInstanceNamed" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class RB_BodyInstance** )( params + function->return_val_offset() );
			}

			void SetHasPhysicsAssetInstance( bool bHasInstance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetHasPhysicsAssetInstance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bHasInstance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateRBBonesFromSpaceBases( bool bMoveUnfixedBodies, bool bTeleport )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UpdateRBBonesFromSpaceBases" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bMoveUnfixedBodies;
				*( bool* )( params + 4 ) = bTeleport;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceSkelUpdate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.ForceSkelUpdate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateAnimations(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UpdateAnimations" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetBonesWithinRadius( Vector Origin, float Radius, int TraceFlags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetBonesWithinRadius" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Vector* )( params + 0 ) = Origin;
				*( float* )( params + 12 ) = Radius;
				*( int* )( params + 16 ) = TraceFlags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddInstanceVertexWeightBoneParented( ScriptName BoneName, bool bPairWithParent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.AddInstanceVertexWeightBoneParented" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( bool* )( params + 8 ) = bPairWithParent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveInstanceVertexWeightBoneParented( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.RemoveInstanceVertexWeightBoneParented" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindInstanceVertexweightBonePair( void* Bones )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.FindInstanceVertexweightBonePair" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = Bones;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void UpdateInstanceVertexWeightBones(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UpdateInstanceVertexWeightBones" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleInstanceVertexWeights( bool bEnable, int LODIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.ToggleInstanceVertexWeights" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bEnable;
				*( int* )( params + 4 ) = LODIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PlayFaceFXAnim( class FaceFXAnimSet* FaceFXAnimSetRef, ScriptArray< wchar_t > AnimName, ScriptArray< wchar_t > GroupName, class SoundCue* SoundCueToPlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.PlayFaceFXAnim" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class FaceFXAnimSet** )( params + 0 ) = FaceFXAnimSetRef;
				*( ScriptArray< wchar_t >* )( params + 4 ) = AnimName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = GroupName;
				*( class SoundCue** )( params + 28 ) = SoundCueToPlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.StopFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPlayingFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.IsPlayingFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DeclareFaceFXRegister( ScriptArray< wchar_t > RegName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.DeclareFaceFXRegister" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = RegName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetFaceFXRegister( ScriptArray< wchar_t > RegName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.GetFaceFXRegister" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = RegName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetFaceFXRegister( ScriptArray< wchar_t > RegName, float RegVal, byte RegOp, float InterpDuration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetFaceFXRegister" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = RegName;
				*( float* )( params + 12 ) = RegVal;
				*( byte* )( params + 16 ) = RegOp;
				*( float* )( params + 20 ) = InterpDuration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFaceFXRegisterEx( ScriptArray< wchar_t > RegName, byte RegOp, float FirstValue, float FirstInterpDuration, float NextValue, float NextInterpDuration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SetFaceFXRegisterEx" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = RegName;
				*( byte* )( params + 12 ) = RegOp;
				*( float* )( params + 16 ) = FirstValue;
				*( float* )( params + 20 ) = FirstInterpDuration;
				*( float* )( params + 24 ) = NextValue;
				*( float* )( params + 28 ) = NextInterpDuration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideBone( int BoneIndex, byte PhysBodyOption )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.HideBone" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( int* )( params + 0 ) = BoneIndex;
				*( byte* )( params + 4 ) = PhysBodyOption;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnHideBone( int BoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UnHideBone" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = BoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsBoneHidden( int BoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.IsBoneHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = BoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void HideBoneByName( ScriptName BoneName, byte PhysBodyOption )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.HideBoneByName" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				*( byte* )( params + 8 ) = PhysBodyOption;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnHideBoneByName( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UnHideBoneByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMeshForBrokenConstraints(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.UpdateMeshForBrokenConstraints" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMaterialSection( int MaterialID, bool bShow, int LODIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.ShowMaterialSection" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = MaterialID;
				*( bool* )( params + 4 ) = bShow;
				*( int* )( params + 8 ) = LODIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayAnim( ScriptName AnimName, float Duration, bool bLoop, bool bRestartIfAlreadyPlaying, float StartTime, bool bPlayBackwards )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.PlayAnim" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )( params + 0 ) = AnimName;
				*( float* )( params + 8 ) = Duration;
				*( bool* )( params + 12 ) = bLoop;
				*( bool* )( params + 16 ) = bRestartIfAlreadyPlaying;
				*( float* )( params + 20 ) = StartTime;
				*( bool* )( params + 24 ) = bPlayBackwards;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( AnimNode, Animations )
			void StopAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.StopAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CreateForceField( class AnimNotify_ForceField* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.CreateForceField" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_ForceField** )( params + 0 ) = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PlayParticleEffect( class AnimNotify_PlayParticleEffect* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.PlayParticleEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_PlayParticleEffect** )( params + 0 ) = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SkelMeshCompOnParticleSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.SkelMeshCompOnParticleSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreakConstraint( Vector Impulse, Vector HitLocation, ScriptName InBoneName, bool bVelChange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshComponent.BreakConstraint" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )( params + 0 ) = Impulse;
				*( Vector* )( params + 12 ) = HitLocation;
				*( ScriptName* )( params + 24 ) = InBoneName;
				*( bool* )( params + 32 ) = bVelChange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( PhysicsAssetInstance, PhysicsAssetInstance )
			ADD_OBJECT( PhysicsAsset, PhysicsAsset )
			ADD_OBJECT( SkeletalMesh, SkeletalMesh )
			ADD_OBJECT( AnimTree, AnimTreeTemplate )
			ADD_VAR( ::FloatProperty, PhysicsWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GlobalAnimRateScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LowUpdateFrameRate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShouldIgnoreParentAnimComponent, 0x1 )
			ADD_VAR( ::IntProperty, ForcedLodModel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinLodModel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PredictedLODLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OldPredictedLODLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDistanceFactor, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bForceWireframe, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bForceRefpose, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bOldForceRefPose, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNoSkeletonUpdate, 0x1 )
			ADD_VAR( ::IntProperty, bDisplayBones, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bShowPrePhysBones, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bHideSkin, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bForceRawOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bIgnoreControllers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bTransformFromAnimParent, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TickTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, InitTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CachedAtomsTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bUseSingleBodyPhysics, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bRequiredBonesUpToDate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinDistFactorForKinematicUpdate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FramesPhysicsAsleep, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSkipAllUpdateWhenPhysicsAsleep, 0x1 )
			ADD_VAR( ::BoolProperty, bConsiderAllBodiesForBounds, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdateSkelWhenNotRendered, 0x4 )
			ADD_VAR( ::BoolProperty, bIgnoreControllersWhenNotRendered, 0x8 )
			ADD_VAR( ::BoolProperty, bTickAnimNodesWhenNotRendered, 0x10 )
			ADD_VAR( ::BoolProperty, bNotUpdatingKinematicDueToDistance, 0x20 )
			ADD_VAR( ::BoolProperty, bForceDiscardRootMotion, 0x40 )
			ADD_VAR( ::BoolProperty, bRootMotionModeChangeNotify, 0x80 )
			ADD_VAR( ::BoolProperty, bRootMotionExtractedNotify, 0x100 )
			ADD_VAR( ::BoolProperty, bDisableFaceFXMaterialInstanceCreation, 0x200 )
			ADD_VAR( ::BoolProperty, bAnimTreeInitialised, 0x400 )
			ADD_VAR( ::BoolProperty, bForceMeshObjectUpdate, 0x800 )
			ADD_VAR( ::BoolProperty, bHasPhysicsAssetInstance, 0x1000 )
			ADD_VAR( ::BoolProperty, bUpdateKinematicBonesFromAnimation, 0x2000 )
			ADD_VAR( ::BoolProperty, bUpdateJointsFromAnimation, 0x4000 )
			ADD_VAR( ::BoolProperty, bSkelCompFixed, 0x8000 )
			ADD_VAR( ::BoolProperty, bHasHadPhysicsBlendedIn, 0x10000 )
			ADD_VAR( ::BoolProperty, bForceUpdateAttachmentsInTick, 0x20000 )
			ADD_VAR( ::BoolProperty, bEnableFullAnimWeightBodies, 0x40000 )
			ADD_VAR( ::BoolProperty, bPerBoneVolumeEffects, 0x80000 )
			ADD_VAR( ::BoolProperty, bPerBoneMotionBlur, 0x100000 )
			ADD_VAR( ::BoolProperty, bSyncActorLocationToRootRigidBody, 0x200000 )
			ADD_VAR( ::BoolProperty, bUseRawData, 0x400000 )
			ADD_VAR( ::BoolProperty, bDisableWarningWhenAnimNotFound, 0x800000 )
			ADD_VAR( ::BoolProperty, bOverrideAttachmentOwnerVisibility, 0x1000000 )
			ADD_VAR( ::BoolProperty, bNeedsToDeleteHitMask, 0x2000000 )
			ADD_VAR( ::BoolProperty, bPauseAnims, 0x4000000 )
			ADD_VAR( ::BoolProperty, bChartDistanceFactor, 0x8000000 )
			ADD_VAR( ::BoolProperty, bEnableLineCheckWithBounds, 0x10000000 )
			ADD_VAR( ::BoolProperty, bCanHighlightSelectedSections, 0x20000000 )
			ADD_STRUCT( ::VectorProperty, LineCheckBoundsScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableClothSimulation, 0x1 )
			ADD_VAR( ::BoolProperty, bDisableClothCollision, 0x2 )
			ADD_VAR( ::BoolProperty, bClothFrozen, 0x4 )
			ADD_VAR( ::BoolProperty, bAutoFreezeClothWhenNotRendered, 0x8 )
			ADD_VAR( ::BoolProperty, bClothAwakeOnStartup, 0x10 )
			ADD_VAR( ::BoolProperty, bClothBaseVelClamp, 0x20 )
			ADD_VAR( ::BoolProperty, bClothBaseVelInterp, 0x40 )
			ADD_VAR( ::BoolProperty, bAttachClothVertsToBaseBody, 0x80 )
			ADD_VAR( ::BoolProperty, bIsClothOnStaticObject, 0x100 )
			ADD_VAR( ::BoolProperty, bUpdatedFixedClothVerts, 0x200 )
			ADD_VAR( ::BoolProperty, bClothPositionalDampening, 0x400 )
			ADD_VAR( ::BoolProperty, bClothWindRelativeToOwner, 0x800 )
			ADD_VAR( ::BoolProperty, bRecentlyRendered, 0x1000 )
			ADD_VAR( ::BoolProperty, bCacheAnimSequenceNodes, 0x2000 )
			ADD_VAR( ::BoolProperty, bNeedsInstanceWeightUpdate, 0x4000 )
			ADD_VAR( ::BoolProperty, bAlwaysUseInstanceWeights, 0x8000 )
			ADD_VAR( ::BoolProperty, bUpdateComposeSkeletonPasses, 0x10000 )
			ADD_VAR( ::BoolProperty, bValidTemporarySavedAnimSets, 0x20000 )
			ADD_STRUCT( ::VectorProperty, FrozenLocalToWorldPos, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, FrozenLocalToWorldRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ClothExternalForce, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ClothWind, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ClothBaseVelClampRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClothBlendWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClothDynamicBlendWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClothBlendMinDistanceFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClothBlendMaxDistanceFactor, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MinPosDampRange, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MaxPosDampRange, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MinPosDampScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MaxPosDampScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumClothMeshVerts, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumClothMeshIndices, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumClothMeshParentIndices, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ClothDirtyBufferFlag, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ClothRBChannel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClothForceScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClothImpulseScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClothAttachmentTearFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bClothUseCompartment, 0x1 )
			ADD_VAR( ::FloatProperty, MinDistanceForClothReset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastClothLocation, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ApexClothingRBChannel, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoFreezeApexClothingWhenNotRendered, 0x1 )
			ADD_STRUCT( ::VectorProperty, WindVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WindVelocityBlendTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSkipInitClothing, 0x1 )
			ADD_VAR( ::IntProperty, SoftBodySceneIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableSoftBodySimulation, 0x1 )
			ADD_VAR( ::IntProperty, NumSoftBodyTetraVerts, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumSoftBodyTetraIndices, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SoftBodyImpulseScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSoftBodyFrozen, 0x1 )
			ADD_VAR( ::BoolProperty, bAutoFreezeSoftBodyWhenNotRendered, 0x2 )
			ADD_VAR( ::BoolProperty, bSoftBodyAwakeOnStartup, 0x4 )
			ADD_VAR( ::BoolProperty, bSoftBodyUseCompartment, 0x8 )
			ADD_VAR( ::ByteProperty, SoftBodyRBChannel, 0xFFFFFFFF )
			ADD_OBJECT( Material, LimitMaterial )
			ADD_STRUCT( ::VectorProperty, RootMotionVelocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RootBoneTranslation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RootMotionAccelScale, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RootMotionMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PreviousRMM, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PendingRMM, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, OldPendingRMM, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bRMMOneFrameDelay, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RootMotionRotationMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FaceFXBlendMode, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ProgressiveDrawingFraction, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CustomSortAlternateIndexMode, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
