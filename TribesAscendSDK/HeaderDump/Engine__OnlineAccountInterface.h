#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineAccountInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineAccountInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineAccountInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineAccountInterface : public Interface
	{
	public:
			bool CreateOnlineAccount( ScriptArray< wchar_t > UserName, ScriptArray< wchar_t > Password, ScriptArray< wchar_t > EmailAddress, ScriptArray< wchar_t > ProductKey )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.CreateOnlineAccount" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = UserName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Password;
				*( ScriptArray< wchar_t >* )( params + 24 ) = EmailAddress;
				*( ScriptArray< wchar_t >* )( params + 36 ) = ProductKey;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnCreateOnlineAccountCompleted( byte ErrorStatus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.OnCreateOnlineAccountCompleted" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = ErrorStatus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddCreateOnlineAccountCompletedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.AddCreateOnlineAccountCompletedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCreateOnlineAccountCompletedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.ClearCreateOnlineAccountCompletedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CreateLocalAccount( ScriptArray< wchar_t > UserName, ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.CreateLocalAccount" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = UserName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RenameLocalAccount( ScriptArray< wchar_t > NewUserName, ScriptArray< wchar_t > OldUserName, ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.RenameLocalAccount" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = NewUserName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = OldUserName;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DeleteLocalAccount( ScriptArray< wchar_t > UserName, ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.DeleteLocalAccount" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = UserName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetLocalAccountNames(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineAccountInterface.GetLocalAccountNames" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
