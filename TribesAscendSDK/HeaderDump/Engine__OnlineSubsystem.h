#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineSubsystem." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineSubsystem." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineSubsystem." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineSubsystem : public Object
	{
	public:
			void SetDebugSpewLevel( int DebugSpewLevel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetDebugSpewLevel" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = DebugSpewLevel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DumpVoiceRegistration(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.DumpVoiceRegistration" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DumpSessionState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.DumpSessionState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DumpGameSettings( class OnlineGameSettings* GameSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.DumpGameSettings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class OnlineGameSettings** )params = GameSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetNumSupportedLogins(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.GetNumSupportedLogins" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetBuildUniqueId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.GetBuildUniqueId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool StringToUniqueNetId( ScriptArray< wchar_t > UniqueNetIdString, void* &out_UniqueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.StringToUniqueNetId" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )params = UniqueNetIdString;
				*( void** )( params + 12 ) = out_UniqueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_UniqueId = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > UniqueNetIdToString( void* &IdToConvert )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.UniqueNetIdToString" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = IdToConvert;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				IdToConvert = *( void** )params;
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			class Object* GetNamedInterface( ScriptName InterfaceName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.GetNamedInterface" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = InterfaceName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Object** )( params + function->return_val_offset() );
			}

			void SetNamedInterface( ScriptName InterfaceName, class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetNamedInterface" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = InterfaceName;
				*( class Object** )( params + 8 ) = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetGameChatInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetGameChatInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetTitleFileInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetTitleFileInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetPartyChatInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetPartyChatInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetNewsInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetNewsInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetStatsInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetStatsInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetVoiceInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetVoiceInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetContentInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetContentInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetGameInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetGameInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetSystemInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetSystemInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetPlayerInterfaceEx( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetPlayerInterfaceEx" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetPlayerInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetPlayerInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetAccountInterface( class Object* NewInterface )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.SetAccountInterface" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Object** )params = NewInterface;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Exit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.Exit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PostInit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.PostInit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSubsystem.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::StrProperty, IniLocPatcherClassName, 0xFFFFFFFF )
			ADD_OBJECT( IniLocPatcher, Patcher )
			ADD_VAR( ::BoolProperty, bUseBuildIdOverride, 0x1 )
			ADD_VAR( ::IntProperty, BuildIdOverride, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AsyncMinCompletionTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
