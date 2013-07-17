#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PrimitiveComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PrimitiveComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PrimitiveComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PrimitiveComponent : public ActorComponent
	{
	public:
			void SetBlockRigidBody( bool bNewBlockRigidBody )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetBlockRigidBody" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewBlockRigidBody;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRBLinearVelocity( Vector NewVel, bool bAddToCurrent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBLinearVelocity" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = NewVel;
				*( bool* )( params + 12 ) = bAddToCurrent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, Tag, 0xFFFFFFFF )
			void AddImpulse( Vector Impulse, Vector Position, ScriptName BoneName, bool bVelChange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.AddImpulse" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )( params + 0 ) = Impulse;
				*( Vector* )( params + 12 ) = Position;
				*( ScriptName* )( params + 24 ) = BoneName;
				*( bool* )( params + 32 ) = bVelChange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddRadialImpulse( Vector Origin, float Radius, float Strength, byte Falloff, bool bVelChange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.AddRadialImpulse" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( Vector* )( params + 0 ) = Origin;
				*( float* )( params + 12 ) = Radius;
				*( float* )( params + 16 ) = Strength;
				*( byte* )( params + 20 ) = Falloff;
				*( bool* )( params + 24 ) = bVelChange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddForce( Vector Force, Vector Position, ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.AddForce" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Vector* )( params + 0 ) = Force;
				*( Vector* )( params + 12 ) = Position;
				*( ScriptName* )( params + 24 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddRadialForce( Vector Origin, float Radius, float Strength, byte Falloff )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.AddRadialForce" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( Vector* )( params + 0 ) = Origin;
				*( float* )( params + 12 ) = Radius;
				*( float* )( params + 16 ) = Strength;
				*( byte* )( params + 20 ) = Falloff;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddTorque( Vector Torque, ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.AddTorque" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = Torque;
				*( ScriptName* )( params + 12 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRBAngularVelocity( Vector NewAngVel, bool bAddToCurrent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBAngularVelocity" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = NewAngVel;
				*( bool* )( params + 12 ) = bAddToCurrent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RetardRBLinearVelocity( Vector RetardDir, float VelScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.RetardRBLinearVelocity" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = RetardDir;
				*( float* )( params + 12 ) = VelScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRBPosition( Vector NewPos, ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBPosition" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = NewPos;
				*( ScriptName* )( params + 12 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRBRotation( Rotator NewRot, ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBRotation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Rotator* )( params + 0 ) = NewRot;
				*( ScriptName* )( params + 12 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WakeRigidBody( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.WakeRigidBody" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PutRigidBodyToSleep( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.PutRigidBodyToSleep" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RigidBodyIsAwake( ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.RigidBodyIsAwake" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetRBCollidesWithChannel( byte Channel, bool bNewCollides )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBCollidesWithChannel" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = Channel;
				*( bool* )( params + 4 ) = bNewCollides;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRBCollisionChannels( void* Channels )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBCollisionChannels" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = Channels;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRBChannel( byte Channel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBChannel" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Channel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetNotifyRigidBodyCollision( bool bNewNotifyRigidBodyCollision )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetNotifyRigidBodyCollision" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewNotifyRigidBodyCollision;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitRBPhys(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.InitRBPhys" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPhysMaterialOverride( class PhysicalMaterial* NewPhysMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetPhysMaterialOverride" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicalMaterial** )( params + 0 ) = NewPhysMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class RB_BodyInstance* GetRootBodyInstance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.GetRootBodyInstance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class RB_BodyInstance** )( params + function->return_val_offset() );
			}

			void SetRBDominanceGroup( byte InDomGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRBDominanceGroup" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = InDomGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldComponentAddToScene(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.ShouldComponentAddToScene" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetHidden( bool NewHidden )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = NewHidden;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOwnerNoSee( bool bNewOwnerNoSee )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetOwnerNoSee" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewOwnerNoSee;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOnlyOwnerSee( bool bNewOnlyOwnerSee )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetOnlyOwnerSee" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewOnlyOwnerSee;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetIgnoreOwnerHidden( bool bNewIgnoreOwnerHidden )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetIgnoreOwnerHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewIgnoreOwnerHidden;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetShadowParent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetShadowParent" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLightEnvironment(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetLightEnvironment" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCullDistance( float NewCullDistance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetCullDistance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = NewCullDistance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLightingChannels( void* NewLightingChannels )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetLightingChannels" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = NewLightingChannels;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDepthPriorityGroup( byte NewDepthPriorityGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetDepthPriorityGroup" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = NewDepthPriorityGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetViewOwnerDepthPriorityGroup( bool bNewUseViewOwnerDepthPriorityGroup, byte NewViewOwnerDepthPriorityGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetViewOwnerDepthPriorityGroup" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( bool* )( params + 0 ) = bNewUseViewOwnerDepthPriorityGroup;
				*( byte* )( params + 4 ) = NewViewOwnerDepthPriorityGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTraceBlocking( bool NewBlockZeroExtent, bool NewBlockNonZeroExtent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetTraceBlocking" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = NewBlockZeroExtent;
				*( bool* )( params + 4 ) = NewBlockNonZeroExtent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActorCollision( bool NewCollideActors, bool NewBlockActors, bool NewAlwaysCheckCollision )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetActorCollision" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = NewCollideActors;
				*( bool* )( params + 4 ) = NewBlockActors;
				*( bool* )( params + 8 ) = NewAlwaysCheckCollision;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTranslation( Vector NewTranslation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetTranslation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = NewTranslation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRotation( Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetRotation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetScale( float NewScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = NewScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetScale3D( Vector NewScale3D )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetScale3D" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = NewScale3D;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAbsolute( bool NewAbsoluteTranslation, bool NewAbsoluteRotation, bool NewAbsoluteScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.SetAbsolute" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = NewAbsoluteTranslation;
				*( bool* )( params + 4 ) = NewAbsoluteRotation;
				*( bool* )( params + 8 ) = NewAbsoluteScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetPosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.GetPosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Rotator GetRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.GetRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			byte ClosestPointOnComponentToPoint( Vector &POI, Vector &Extent, Vector &OutPointA, Vector &OutPointB )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.ClosestPointOnComponentToPoint" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )( params + 0 ) = POI;
				*( Vector* )( params + 12 ) = Extent;
				*( Vector* )( params + 24 ) = OutPointA;
				*( Vector* )( params + 36 ) = OutPointB;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				POI = *( Vector* )( params + 0 );
				Extent = *( Vector* )( params + 12 );
				OutPointA = *( Vector* )( params + 24 );
				OutPointB = *( Vector* )( params + 36 );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte ClosestPointOnComponentToComponent( Vector &PointOnComponentA, Vector &PointOnComponentB )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PrimitiveComponent.ClosestPointOnComponentToComponent" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )( params + 4 ) = PointOnComponentA;
				*( Vector* )( params + 16 ) = PointOnComponentB;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PointOnComponentA = *( Vector* )( params + 4 );
				PointOnComponentB = *( Vector* )( params + 16 );
				return *( byte* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, ThreadTag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DetachFence, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LocalToWorldDeterminant, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MotionBlurInfoIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinDrawDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MassiveLODDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDrawDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CachedMaxDrawDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CullDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CachedCullDistance, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DepthPriorityGroup, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ViewOwnerDepthPriorityGroup, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DetailMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RBChannel, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RBDominanceGroup, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PreviewEnvironmentShadowing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MotionBlurScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseViewOwnerDepthPriorityGroup, 0x1 )
			ADD_VAR( ::BoolProperty, bAllowCullDistanceVolume, 0x2 )
			ADD_VAR( ::BoolProperty, HiddenGame, 0x4 )
			ADD_VAR( ::BoolProperty, HiddenEditor, 0x8 )
			ADD_VAR( ::BoolProperty, bOwnerNoSee, 0x10 )
			ADD_VAR( ::BoolProperty, bOnlyOwnerSee, 0x20 )
			ADD_VAR( ::BoolProperty, bIgnoreOwnerHidden, 0x40 )
			ADD_VAR( ::BoolProperty, bUseAsOccluder, 0x80 )
			ADD_VAR( ::BoolProperty, bAllowApproximateOcclusion, 0x100 )
			ADD_VAR( ::BoolProperty, bFirstFrameOcclusion, 0x200 )
			ADD_VAR( ::BoolProperty, bIgnoreNearPlaneIntersection, 0x400 )
			ADD_VAR( ::BoolProperty, bSelectable, 0x800 )
			ADD_VAR( ::BoolProperty, bForceMipStreaming, 0x1000 )
			ADD_VAR( ::BoolProperty, bAcceptsDecals, 0x2000 )
			ADD_VAR( ::BoolProperty, bAcceptsDecalsDuringGameplay, 0x4000 )
			ADD_VAR( ::BoolProperty, bAcceptsStaticDecals, 0x8000 )
			ADD_VAR( ::BoolProperty, bAcceptsDynamicDecals, 0x10000 )
			ADD_VAR( ::BoolProperty, bIsRefreshingDecals, 0x20000 )
			ADD_VAR( ::BoolProperty, bAllowDecalAutomaticReAttach, 0x40000 )
			ADD_VAR( ::BoolProperty, CastShadow, 0x80000 )
			ADD_VAR( ::BoolProperty, bForceDirectLightMap, 0x100000 )
			ADD_VAR( ::BoolProperty, bCastDynamicShadow, 0x200000 )
			ADD_VAR( ::BoolProperty, bUsesPlayerShadowFadeResolution, 0x400000 )
			ADD_VAR( ::BoolProperty, bSelfShadowOnly, 0x800000 )
			ADD_VAR( ::BoolProperty, bAcceptsDynamicDominantLightShadows, 0x1000000 )
			ADD_VAR( ::BoolProperty, bCastHiddenShadow, 0x2000000 )
			ADD_VAR( ::BoolProperty, bCastShadowAsTwoSided, 0x4000000 )
			ADD_VAR( ::BoolProperty, bAcceptsLights, 0x8000000 )
			ADD_VAR( ::BoolProperty, bAcceptsDynamicLights, 0x10000000 )
			ADD_VAR( ::BoolProperty, bUseOnePassLightingOnTranslucency, 0x20000000 )
			ADD_VAR( ::BoolProperty, bUsePrecomputedShadows, 0x40000000 )
			ADD_VAR( ::BoolProperty, bHasExplicitShadowParent, 0x80000000 )
			ADD_VAR( ::BoolProperty, bCullModulatedShadowOnBackfaces, 0x1 )
			ADD_VAR( ::BoolProperty, bCullModulatedShadowOnEmissive, 0x2 )
			ADD_VAR( ::BoolProperty, bAllowAmbientOcclusion, 0x4 )
			ADD_VAR( ::BoolProperty, CollideActors, 0x8 )
			ADD_VAR( ::BoolProperty, AlwaysCheckCollision, 0x10 )
			ADD_VAR( ::BoolProperty, BlockActors, 0x20 )
			ADD_VAR( ::BoolProperty, BlockZeroExtent, 0x40 )
			ADD_VAR( ::BoolProperty, BlockNonZeroExtent, 0x80 )
			ADD_VAR( ::BoolProperty, CanBlockCamera, 0x100 )
			ADD_VAR( ::BoolProperty, BlockRigidBody, 0x200 )
			ADD_VAR( ::BoolProperty, bDisableAllRigidBody, 0x400 )
			ADD_VAR( ::BoolProperty, bSkipRBGeomCreation, 0x800 )
			ADD_VAR( ::BoolProperty, bNotifyRigidBodyCollision, 0x1000 )
			ADD_VAR( ::BoolProperty, bFluidDrain, 0x2000 )
			ADD_VAR( ::BoolProperty, bFluidTwoWay, 0x4000 )
			ADD_VAR( ::BoolProperty, bIgnoreRadialImpulse, 0x8000 )
			ADD_VAR( ::BoolProperty, bIgnoreRadialForce, 0x10000 )
			ADD_VAR( ::BoolProperty, bIgnoreForceField, 0x20000 )
			ADD_VAR( ::BoolProperty, bUseCompartment, 0x40000 )
			ADD_VAR( ::BoolProperty, AlwaysLoadOnClient, 0x80000 )
			ADD_VAR( ::BoolProperty, AlwaysLoadOnServer, 0x100000 )
			ADD_VAR( ::BoolProperty, bIgnoreHiddenActorsMembership, 0x200000 )
			ADD_VAR( ::BoolProperty, AbsoluteTranslation, 0x400000 )
			ADD_VAR( ::BoolProperty, AbsoluteRotation, 0x800000 )
			ADD_VAR( ::BoolProperty, AbsoluteScale, 0x1000000 )
			ADD_VAR( ::BoolProperty, bAllowShadowFade, 0x2000000 )
			ADD_VAR( ::BoolProperty, bWasSNFiltered, 0x4000000 )
			ADD_VAR( ::IntProperty, TranslucencySortPriority, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VisibilityId, 0xFFFFFFFF )
			ADD_OBJECT( PhysicalMaterial, PhysMaterialOverride )
			ADD_OBJECT( RB_BodyInstance, BodyInstance )
			ADD_STRUCT( ::VectorProperty, Translation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, Rotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Scale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Scale3D, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoundsScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastSubmitTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastRenderTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ScriptRigidBodyCollisionThreshold, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
