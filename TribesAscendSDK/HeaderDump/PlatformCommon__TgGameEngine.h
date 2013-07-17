#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " PlatformCommon.TgGameEngine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty PlatformCommon.TgGameEngine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty PlatformCommon.TgGameEngine." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TgGameEngine : public GameEngine
	{
	public:
			void OnMarshalEvent( void* pMarEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.OnMarshalEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = pMarEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetFunction( int nFunction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SetFunction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = nFunction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetFieldInt( int nToken, int IntValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SetFieldInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = nToken;
				*( int* )( params + 4 ) = IntValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetFieldFloat( int nToken, float FloatValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SetFieldFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = nToken;
				*( float* )( params + 4 ) = FloatValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetFieldString( int nToken, ScriptArray< wchar_t > StrValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SetFieldString" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = nToken;
				*( ScriptArray< wchar_t >* )( params + 4 ) = StrValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearMarshal(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.ClearMarshal" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMarshal( void* qwPlayerId, bool bLowPriority )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SendMarshal" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = qwPlayerId;
				*( bool* )( params + 8 ) = bLowPriority;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMarshalAll( bool bLowPriority )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SendMarshalAll" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bLowPriority;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetFieldInt( int nToken, int &IntValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.GetFieldInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = nToken;
				*( int* )( params + 4 ) = IntValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				IntValue = *( int* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetFieldFloat( int nToken, float &FloatValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.GetFieldFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = nToken;
				*( float* )( params + 4 ) = FloatValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FloatValue = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetFieldString( int nToken, ScriptArray< wchar_t > &StrValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.GetFieldString" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = nToken;
				*( ScriptArray< wchar_t >* )( params + 4 ) = StrValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				StrValue = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddMarshalEventDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.AddMarshalEventDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMarshalEventDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.ClearMarshalEventDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendCtrlRequest( ScriptArray< wchar_t > fsRequest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SendCtrlRequest" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = fsRequest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendGameRequest( ScriptArray< wchar_t > fsRequest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.SendGameRequest" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = fsRequest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HandlePlayerCommandInput( ScriptArray< wchar_t > FSCommand, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function PlatformCommon.TgGameEngine.HandlePlayerCommandInput" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = FSCommand;
				*( class PlayerController** )( params + 12 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
