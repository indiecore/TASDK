#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DecalManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DecalManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DecalManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DecalManager : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, DecalDepthBias, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DecalLifeSpan, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxActiveDecals, 0xFFFFFFFF )
			bool AreDynamicDecalsEnabled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DecalManager.AreDynamicDecalsEnabled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DecalFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DecalManager.DecalFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanSpawnDecals(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DecalManager.CanSpawnDecals" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetDecalParameters( class MaterialInterface* DecalMaterial, Vector DecalLocation, Rotator DecalOrientation, float Width, float Height, float Thickness, bool bNoClip, float DecalRotation, bool bProjectOnTerrain, bool bProjectOnSkeletalMeshes, ScriptName HitBone, int HitNodeIndex, int HitLevelIndex, int InFracturedStaticMeshComponentIndex, float DepthBias, void* BlendRange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DecalManager.SetDecalParameters" );
				byte *params = ( byte* )( malloc( 96 ) );
				*( class MaterialInterface** )( params + 4 ) = DecalMaterial;
				*( Vector* )( params + 8 ) = DecalLocation;
				*( Rotator* )( params + 20 ) = DecalOrientation;
				*( float* )( params + 32 ) = Width;
				*( float* )( params + 36 ) = Height;
				*( float* )( params + 40 ) = Thickness;
				*( bool* )( params + 44 ) = bNoClip;
				*( float* )( params + 48 ) = DecalRotation;
				*( bool* )( params + 56 ) = bProjectOnTerrain;
				*( bool* )( params + 60 ) = bProjectOnSkeletalMeshes;
				*( ScriptName* )( params + 64 ) = HitBone;
				*( int* )( params + 72 ) = HitNodeIndex;
				*( int* )( params + 76 ) = HitLevelIndex;
				*( int* )( params + 80 ) = InFracturedStaticMeshComponentIndex;
				*( float* )( params + 84 ) = DepthBias;
				*( void** )( params + 88 ) = BlendRange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetPooledComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DecalManager.GetPooledComponent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* SpawnDecal( class MaterialInterface* DecalMaterial, Vector DecalLocation, Rotator DecalOrientation, float Width, float Height, float Thickness, bool bNoClip, float DecalRotation, bool bProjectOnTerrain, bool bProjectOnSkeletalMeshes, ScriptName HitBone, int HitNodeIndex, int HitLevelIndex, float InDecalLifeSpan, int InFracturedStaticMeshComponentIndex, float InDepthBias, void* InBlendRange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DecalManager.SpawnDecal" );
				byte *params = ( byte* )( malloc( 96 ) );
				*( class MaterialInterface** )( params + 0 ) = DecalMaterial;
				*( Vector* )( params + 4 ) = DecalLocation;
				*( Rotator* )( params + 16 ) = DecalOrientation;
				*( float* )( params + 28 ) = Width;
				*( float* )( params + 32 ) = Height;
				*( float* )( params + 36 ) = Thickness;
				*( bool* )( params + 40 ) = bNoClip;
				*( float* )( params + 44 ) = DecalRotation;
				*( bool* )( params + 52 ) = bProjectOnTerrain;
				*( bool* )( params + 56 ) = bProjectOnSkeletalMeshes;
				*( ScriptName* )( params + 60 ) = HitBone;
				*( int* )( params + 68 ) = HitNodeIndex;
				*( int* )( params + 72 ) = HitLevelIndex;
				*( float* )( params + 76 ) = InDecalLifeSpan;
				*( int* )( params + 80 ) = InFracturedStaticMeshComponentIndex;
				*( float* )( params + 84 ) = InDepthBias;
				*( void** )( params + 88 ) = InBlendRange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
