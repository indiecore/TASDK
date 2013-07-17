#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkeletalMeshActorMAT." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkeletalMeshActorMAT." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkeletalMeshActorMAT." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkeletalMeshActorMAT : public SkeletalMeshCinematicActor
	{
	public:
			void MAT_SetAnimWeights(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.MAT_SetAnimWeights" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_SetMorphWeight( ScriptName MorphNodeName, float MorphWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.MAT_SetMorphWeight" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = MorphNodeName;
				*( float* )( params + 8 ) = MorphWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_SetSkelControlScale( ScriptName SkelControlName, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.MAT_SetSkelControlScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SkelControlName;
				*( float* )( params + 8 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CacheAnimNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.CacheAnimNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAnimNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.ClearAnimNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAnimPosition( ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.SetAnimPosition" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )( params + 0 ) = SlotName;
				*( int* )( params + 8 ) = ChannelIndex;
				*( ScriptName* )( params + 12 ) = InAnimSeqName;
				*( float* )( params + 20 ) = InPosition;
				*( bool* )( params + 24 ) = bFireNotifies;
				*( bool* )( params + 28 ) = bLooping;
				*( bool* )( params + 32 ) = bEnableRootMotion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_SetAnimPosition( ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.MAT_SetAnimPosition" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )( params + 0 ) = SlotName;
				*( int* )( params + 8 ) = ChannelIndex;
				*( ScriptName* )( params + 12 ) = InAnimSeqName;
				*( float* )( params + 20 ) = InPosition;
				*( bool* )( params + 24 ) = bFireNotifies;
				*( bool* )( params + 28 ) = bLooping;
				*( bool* )( params + 32 ) = bEnableRootMotion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.FinishAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMorphWeight( ScriptName MorphNodeName, float MorphWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.SetMorphWeight" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = MorphNodeName;
				*( float* )( params + 8 ) = MorphWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkelControlScale( ScriptName SkelControlName, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActorMAT.SetSkelControlScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SkelControlName;
				*( float* )( params + 8 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
