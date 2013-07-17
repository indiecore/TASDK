#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.OnlineSubsystemCommonImpl." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.OnlineSubsystemCommonImpl." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.OnlineSubsystemCommonImpl." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineSubsystemCommonImpl : public OnlineSubsystem
	{
	public:
			ADD_OBJECT( OnlineGameInterfaceImpl, GameInterfaceImpl )
			ADD_VAR( ::BoolProperty, bIsUsingSpeechRecognition, 0x1 )
			ADD_VAR( ::IntProperty, MaxRemoteTalkers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxLocalTalkers, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetPlayerNicknameFromIndex( int UserIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerNicknameFromIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = UserIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void* GetPlayerUniqueNetIdFromIndex( int UserIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerUniqueNetIdFromIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = UserIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool IsPlayerInSession( ScriptName SessionName, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineSubsystemCommonImpl.IsPlayerInSession" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetRegisteredPlayers( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineSubsystemCommonImpl.GetRegisteredPlayers" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
