#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxInteraction." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxInteraction." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxInteraction." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxInteraction : public Interaction
	{
	public:
			class GFxMoviePlayer* GetFocusMovie( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxInteraction.GetFocusMovie" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxMoviePlayer** )( params + function->return_val_offset() );
			}

			void NotifyGameSessionEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxInteraction.NotifyGameSessionEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPlayerAdded( int PlayerIndex, class LocalPlayer* AddedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxInteraction.NotifyPlayerAdded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = AddedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPlayerRemoved( int PlayerIndex, class LocalPlayer* RemovedPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxInteraction.NotifyPlayerRemoved" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlayerIndex;
				*( class LocalPlayer** )( params + 4 ) = RemovedPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CloseAllMoviePlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxInteraction.CloseAllMoviePlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
