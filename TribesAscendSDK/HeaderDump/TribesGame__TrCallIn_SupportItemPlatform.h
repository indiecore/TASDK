#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn_SupportItemPlatform." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn_SupportItemPlatform." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn_SupportItemPlatform." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn_SupportItemPlatform : public Actor
	{
	public:
			ADD_OBJECT( TrGameObjective, r_DeployedItem )
			ADD_VAR( ::ByteProperty, DefenderTeamIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ItemAttachPointName, 0xFFFFFFFF )
			void GetBoundingCylinder( float &CollisionRadius, float &CollisionHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_SupportItemPlatform.GetBoundingCylinder" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = CollisionRadius;
				*( float* )( params + 4 ) = CollisionHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CollisionRadius = *( float* )params;
				CollisionHeight = *( float* )( params + 4 );
			}

			void Init( class Actor* DeployableOwner, ScriptClass* GameObjectiveClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_SupportItemPlatform.Init" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = DeployableOwner;
				*( ScriptClass** )( params + 4 ) = GameObjectiveClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte ScriptGetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_SupportItemPlatform.ScriptGetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void HideMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_SupportItemPlatform.HideMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_SupportItemPlatform.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
