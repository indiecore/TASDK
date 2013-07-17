#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGameViewportClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGameViewportClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGameViewportClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGameViewportClient : public UDKGameViewportClient
	{
	public:
			ADD_VAR( ::StrProperty, LevelActionMessages, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ProgressMessageSceneClassName, 0xFFFFFFFF )
			ADD_OBJECT( Font, LoadingScreenHintMessageFont )
			ADD_OBJECT( Font, LoadingScreenGameTypeNameFont )
			ADD_OBJECT( Font, LoadingScreenMapNameFont )
			ADD_VAR( ::StrProperty, UTFrontEndString, 0xFFFFFFFF )
			void PostRender( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameViewportClient.PostRender" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTransition( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameViewportClient.DrawTransition" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderHeader( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameViewportClient.RenderHeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateActiveSplitscreenType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameViewportClient.UpdateActiveSplitscreenType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetProgressMessage( byte MessageType, ScriptArray< wchar_t > Message, ScriptArray< wchar_t > Title, bool bIgnoreFutureNetworkMessages )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameViewportClient.SetProgressMessage" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )( params + 0 ) = MessageType;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Message;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Title;
				*( bool* )( params + 28 ) = bIgnoreFutureNetworkMessages;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyConnectionError( ScriptArray< wchar_t > Message, ScriptArray< wchar_t > Title )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameViewportClient.NotifyConnectionError" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Message;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Title;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
