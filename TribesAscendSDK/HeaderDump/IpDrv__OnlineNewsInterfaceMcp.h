#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.OnlineNewsInterfaceMcp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.OnlineNewsInterfaceMcp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.OnlineNewsInterfaceMcp." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineNewsInterfaceMcp : public MCPBase
	{
	public:
			void OnReadNewsCompleted( bool bWasSuccessful, byte NewsType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineNewsInterfaceMcp.OnReadNewsCompleted" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				*( byte* )( params + 4 ) = NewsType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bNeedsTicking, 0x1 )
			bool ReadNews( byte LocalUserNum, byte NewsType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineNewsInterfaceMcp.ReadNews" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = NewsType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadNewsCompletedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineNewsInterfaceMcp.AddReadNewsCompletedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadNewsCompletedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineNewsInterfaceMcp.ClearReadNewsCompletedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetNews( byte LocalUserNum, byte NewsType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineNewsInterfaceMcp.GetNews" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = NewsType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
