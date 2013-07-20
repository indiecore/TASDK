#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider_OnlinePartyChatList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider_OnlinePartyChatList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider_OnlinePartyChatList." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlinePartyChatList : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
			ADD_VAR( ::StrProperty, IsPlayingThisGameCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, IsInGameSessionCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, IsTalkingCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, IsInPartyVoiceCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, IsLocalCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NatTypeCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NickNameCol, 0xFFFFFFFF )
			void OnRegister( class LocalPlayer* InPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePartyChatList.OnRegister" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = InPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregister(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePartyChatList.OnUnregister" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePartyChatList.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshMembersList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePartyChatList.RefreshMembersList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
