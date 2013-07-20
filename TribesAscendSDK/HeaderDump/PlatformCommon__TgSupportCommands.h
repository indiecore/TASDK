#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " PlatformCommon.TgSupportCommands." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty PlatformCommon.TgSupportCommands." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty PlatformCommon.TgSupportCommands." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TgSupportCommands : public Object
	{
	public:
			ADD_OBJECT( WorldInfo, WorldInfo )
			ADD_OBJECT( PlayerController, PC )
			void gmMatchForce( int nQueueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.gmMatchForce" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nQueueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void gmMatchNext( int nMapId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.gmMatchNext" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nMapId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void gmCommand( ScriptArray< wchar_t > sCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.gmCommand" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = sCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void gmC( ScriptArray< wchar_t > sCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.gmC" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = sCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GPerfDebugFeet( int feet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.GPerfDebugFeet" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = feet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GPerfDebugSkips( int skips )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.GPerfDebugSkips" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = skips;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GPerfDebugRelevMode( int Mode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.GPerfDebugRelevMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Mode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scLog( ScriptArray< wchar_t > LogName, bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scLog" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = LogName;
				*( bool* )( params + 12 ) = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scLogMark( ScriptArray< wchar_t > Comment )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scLogMark" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Comment;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scStartGame( ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scStartGame" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scEndGame( ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scEndGame" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scScore( int nTeam, int nCount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scScore" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = nTeam;
				*( int* )( params + 4 ) = nCount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scTime( int nSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scTimer( ScriptArray< wchar_t > sCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scTimer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = sCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scDemoRec(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scDemoRec" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scDemoStop(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scDemoStop" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scPerfDebugFeet( int feet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scPerfDebugFeet" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = feet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scPerfDebugSkip( int skips )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scPerfDebugSkip" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = skips;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void scPerfDebugRelevMode( int Mode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgSupportCommands.scPerfDebugRelevMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Mode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
