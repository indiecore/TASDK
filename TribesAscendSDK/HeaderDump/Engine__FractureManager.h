#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FractureManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FractureManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FractureManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FractureManager : public Actor
	{
	public:
			float GetFSMFractureCullDistanceScale(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.GetFSMFractureCullDistanceScale" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetFSMDirectSpawnChanceScale(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.GetFSMDirectSpawnChanceScale" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, ExplosionVelScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DestroyMinAngVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DestroyVibrationLevel, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableSpawnChunkEffectForRadialDamage, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableAntiVibration, 0x1 )
			ADD_VAR( ::IntProperty, FSMPartPoolSize, 0xFFFFFFFF )
			void SpawnChunkDestroyEffect( class ParticleSystem* Effect, void* ChunkBox, Vector ChunkDir, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.SpawnChunkDestroyEffect" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class ParticleSystem** )( params + 0 ) = Effect;
				*( void** )( params + 4 ) = ChunkBox;
				*( Vector* )( params + 32 ) = ChunkDir;
				*( float* )( params + 44 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetNumFSMPartsScale(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.GetNumFSMPartsScale" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetFSMRadialSpawnChanceScale(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.GetFSMRadialSpawnChanceScale" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CleanUpFSMParts(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.CleanUpFSMParts" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateFSMParts(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.CreateFSMParts" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetPoolVisibility(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.ResetPoolVisibility" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class FracturedStaticMeshPart* GetFSMPart( class FracturedStaticMeshActor* Parent, Vector SpawnLocation, Rotator SpawnRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.GetFSMPart" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class FracturedStaticMeshActor** )( params + 0 ) = Parent;
				*( Vector* )( params + 4 ) = SpawnLocation;
				*( Rotator* )( params + 16 ) = SpawnRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class FracturedStaticMeshPart** )( params + function->return_val_offset() );
			}

			class FracturedStaticMeshPart* SpawnPartActor( class FracturedStaticMeshActor* Parent, Vector SpawnLocation, Rotator SpawnRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.SpawnPartActor" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class FracturedStaticMeshActor** )( params + 0 ) = Parent;
				*( Vector* )( params + 4 ) = SpawnLocation;
				*( Rotator* )( params + 16 ) = SpawnRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class FracturedStaticMeshPart** )( params + function->return_val_offset() );
			}

			void ReturnPartActor( class FracturedStaticMeshPart* Part )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.ReturnPartActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class FracturedStaticMeshPart** )( params + 0 ) = Part;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.FractureManager.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
