#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.EmitterPool." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.EmitterPool." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.EmitterPool." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class EmitterPool : public Actor
	{
	public:
			void* SpawnEmitter( class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Rotator SpawnRotation, class Actor* AttachToActor, bool bInheritScaleFromBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.SpawnEmitter" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class ParticleSystem** )( params + 0 ) = EmitterTemplate;
				*( Vector* )( params + 4 ) = SpawnLocation;
				*( Rotator* )( params + 16 ) = SpawnRotation;
				*( class Actor** )( params + 28 ) = AttachToActor;
				*( bool* )( params + 32 ) = bInheritScaleFromBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, IdealMaterialInstanceConstants, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IdealStaticMeshComponents, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SMC_MIC_CurrentReductionTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SMC_MIC_ReductionTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLogPoolOverflowList, 0x2 )
			ADD_VAR( ::BoolProperty, bLogPoolOverflow, 0x1 )
			ADD_VAR( ::IntProperty, MaxActiveEffects, 0xFFFFFFFF )
			void OnParticleSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.OnParticleSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReturnToPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.ReturnToPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPoolComponents( bool bClearActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.ClearPoolComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bClearActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FreeStaticMeshComponents(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.FreeStaticMeshComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetFreeStaticMeshComponent( bool bCreateNewObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.GetFreeStaticMeshComponent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bCreateNewObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void FreeMaterialInstanceConstants(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.FreeMaterialInstanceConstants" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class MaterialInstanceConstant* GetFreeMatInstConsts( bool bCreateNewObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.GetFreeMatInstConsts" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bCreateNewObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInstanceConstant** )( params + function->return_val_offset() );
			}

			void* GetPooledComponent( class ParticleSystem* EmitterTemplate, bool bAutoActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.GetPooledComponent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class ParticleSystem** )( params + 0 ) = EmitterTemplate;
				*( bool* )( params + 4 ) = bAutoActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* SpawnEmitterMeshAttachment( class ParticleSystem* EmitterTemplate, ScriptName AttachPointName, bool bAttachToSocket, Vector RelativeLoc, Rotator RelativeRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.SpawnEmitterMeshAttachment" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class ParticleSystem** )( params + 0 ) = EmitterTemplate;
				*( ScriptName* )( params + 8 ) = AttachPointName;
				*( bool* )( params + 16 ) = bAttachToSocket;
				*( Vector* )( params + 20 ) = RelativeLoc;
				*( Rotator* )( params + 32 ) = RelativeRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* SpawnEmitterCustomLifetime( class ParticleSystem* EmitterTemplate, bool bSkipAutoActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.EmitterPool.SpawnEmitterCustomLifetime" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class ParticleSystem** )( params + 0 ) = EmitterTemplate;
				*( bool* )( params + 4 ) = bSkipAutoActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
