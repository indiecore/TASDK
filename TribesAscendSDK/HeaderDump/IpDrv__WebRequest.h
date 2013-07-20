#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.WebRequest." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.WebRequest." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.WebRequest." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class WebRequest : public Object
	{
	public:
			ADD_VAR( ::StrProperty, UserName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Password, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URI, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetVariable( ScriptArray< wchar_t > VariableName, ScriptArray< wchar_t > DefaultValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.GetVariable" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = VariableName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = DefaultValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int GetVariableCount( ScriptArray< wchar_t > VariableName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.GetVariableCount" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = VariableName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetVariableNumber( ScriptArray< wchar_t > VariableName, int Number, ScriptArray< wchar_t > DefaultValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.GetVariableNumber" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = VariableName;
				*( int* )( params + 12 ) = Number;
				*( ScriptArray< wchar_t >* )( params + 16 ) = DefaultValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, RequestType, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RemoteAddr, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ContentLength, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ContentType, 0xFFFFFFFF )
			ScriptArray< wchar_t > DecodeBase64( ScriptArray< wchar_t > Encoded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.DecodeBase64" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Encoded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > EncodeBase64( ScriptArray< wchar_t > Decoded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.EncodeBase64" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Decoded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void AddHeader( ScriptArray< wchar_t > HeaderName, ScriptArray< wchar_t > Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.AddHeader" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = HeaderName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetHeader( ScriptArray< wchar_t > HeaderName, ScriptArray< wchar_t > DefaultValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.GetHeader" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = HeaderName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = DefaultValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void GetHeaders(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.GetHeaders" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddVariable( ScriptArray< wchar_t > VariableName, ScriptArray< wchar_t > Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.AddVariable" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = VariableName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetVariables(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.GetVariables" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Dump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.Dump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessHeaderString( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.ProcessHeaderString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DecodeFormData( ScriptArray< wchar_t > Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.DecodeFormData" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetHexDigit( ScriptArray< wchar_t > D )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebRequest.GetHexDigit" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = D;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
