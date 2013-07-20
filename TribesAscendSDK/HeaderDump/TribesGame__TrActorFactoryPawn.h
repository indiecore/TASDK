#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrActorFactoryPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrActorFactoryPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrActorFactoryPawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrActorFactoryPawn : public UTActorFactoryAI
	{
	public:
			ADD_OBJECT( ScriptClass, FamilyInfo )
			ADD_VAR( ::FloatProperty, GroundSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NextTeam, 0xFFFFFFFF )
			void PostCreateActor( class Actor* NewActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrActorFactoryPawn.PostCreateActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = NewActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
