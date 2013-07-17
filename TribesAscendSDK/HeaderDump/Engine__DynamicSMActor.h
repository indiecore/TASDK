#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DynamicSMActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DynamicSMActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DynamicSMActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DynamicSMActor : public Actor
	{
	public:
			ADD_STRUCT( ::VectorProperty, ReplicatedMeshScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, ReplicatedMeshRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ReplicatedMeshTranslation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSafeBaseIfAsleep, 0x4 )
			ADD_VAR( ::BoolProperty, bPawnCanBaseOn, 0x2 )
			ADD_VAR( ::BoolProperty, bForceStaticDecals, 0x1 )
			ADD_OBJECT( MaterialInterface, ReplicatedMaterial )
			ADD_OBJECT( StaticMesh, ReplicatedMesh )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetMesh( class SeqAct_SetMesh* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.OnSetMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetMesh** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetMaterial( class SeqAct_SetMaterial* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.OnSetMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetMaterial** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetStaticMesh( class StaticMesh* NewMesh, Vector NewTranslation, Rotator NewRotation, Vector NewScale3D )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.SetStaticMesh" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class StaticMesh** )( params + 0 ) = NewMesh;
				*( Vector* )( params + 4 ) = NewTranslation;
				*( Rotator* )( params + 16 ) = NewRotation;
				*( Vector* )( params + 28 ) = NewScale3D;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanBasePawn( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.CanBasePawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Attach( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.Attach" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Detach( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.Detach" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLightEnvironmentToNotBeDynamic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicSMActor.SetLightEnvironmentToNotBeDynamic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
