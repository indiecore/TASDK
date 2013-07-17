#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.InternetLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.InternetLink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.InternetLink." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InternetLink : public Info
	{
	public:
			ADD_VAR( ::IntProperty, DataPending, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Port, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ReceiveMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, OutLineMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LinkMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, InLineMode, 0xFFFFFFFF )
			bool IsDataPending(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.IsDataPending" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ParseURL( ScriptArray< wchar_t > URL, ScriptArray< wchar_t > &Addr, int &PortNum, ScriptArray< wchar_t > &LevelName, ScriptArray< wchar_t > &EntryName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.ParseURL" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = URL;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Addr;
				*( int* )( params + 24 ) = PortNum;
				*( ScriptArray< wchar_t >* )( params + 28 ) = LevelName;
				*( ScriptArray< wchar_t >* )( params + 40 ) = EntryName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Addr = *( ScriptArray< wchar_t >* )( params + 12 );
				PortNum = *( int* )( params + 24 );
				LevelName = *( ScriptArray< wchar_t >* )( params + 28 );
				EntryName = *( ScriptArray< wchar_t >* )( params + 40 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Resolve( ScriptArray< wchar_t > Domain )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.Resolve" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Domain;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetLastError(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.GetLastError" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > IpAddrToString( void* Arg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.IpAddrToString" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = Arg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool StringToIpAddr( ScriptArray< wchar_t > Str, void* &Addr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.StringToIpAddr" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Str;
				*( void** )( params + 12 ) = Addr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Addr = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetLocalIP( void* &Arg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.GetLocalIP" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = Arg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Arg = *( void** )( params + 0 );
			}

			void Resolved( void* Addr )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.Resolved" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = Addr;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResolveFailed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.InternetLink.ResolveFailed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
