#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineChatInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineChatInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineChatInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineChatInterface : public Interface
	{
	public:
			void OnChatMessage( int Channel, ScriptArray< wchar_t > Sender, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineChatInterface.OnChatMessage" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = Channel;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Sender;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddChatMessageDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineChatInterface.AddChatMessageDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearChatMessageDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineChatInterface.ClearChatMessageDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendChatMessage( int Channel, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineChatInterface.SendChatMessage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = Channel;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendPrivateChatMessage( ScriptArray< wchar_t > PlayerName, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineChatInterface.SendPrivateChatMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTeamChange( void* PlayerUid, byte TeamID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineChatInterface.NotifyTeamChange" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )params = PlayerUid;
				*( byte* )( params + 8 ) = TeamID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
