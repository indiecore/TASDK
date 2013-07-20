#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AccessControl." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AccessControl." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AccessControl." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AccessControl : public Info
	{
	public:
			ADD_VAR( ::BoolProperty, bDontAddDefaultAdmin, 0x1 )
			ADD_VAR( ::StrProperty, ACDescText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ACDisplayText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GamePassword, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AdminPassword, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, AdminClass )
			ADD_VAR( ::StrProperty, IdleKickReason, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultKickReason, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KickedMsg, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SessionBanned, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NeedPassword, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WrongPassword, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, IPBanned, 0xFFFFFFFF )
			bool IsAdmin( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.IsAdmin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetAdminPassword( ScriptArray< wchar_t > P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.SetAdminPassword" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetGamePassword( ScriptArray< wchar_t > P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.SetGamePassword" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RequiresPassword(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.RequiresPassword" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Controller* GetControllerFromString( ScriptArray< wchar_t > Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.GetControllerFromString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			void Kick( ScriptArray< wchar_t > Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.Kick" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickBan( ScriptArray< wchar_t > Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.KickBan" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ForceKickPlayer( class PlayerController* C, ScriptArray< wchar_t > KickReason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.ForceKickPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )params = C;
				*( ScriptArray< wchar_t >* )( params + 4 ) = KickReason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool KickPlayer( class PlayerController* C, ScriptArray< wchar_t > KickReason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.KickPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )params = C;
				*( ScriptArray< wchar_t >* )( params + 4 ) = KickReason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AdminLogin( class PlayerController* P, ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.AdminLogin" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )params = P;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AdminLogout( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.AdminLogout" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AdminEntered( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.AdminEntered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdminExited( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.AdminExited" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ParseAdminOptions( ScriptArray< wchar_t > Options )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.ParseAdminOptions" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Options;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ValidLogin( ScriptArray< wchar_t > UserName, ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.ValidLogin" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = UserName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PreLogin( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > Address, ScriptArray< wchar_t > &OutError, bool bSpectator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.PreLogin" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptArray< wchar_t >* )params = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Address;
				*( ScriptArray< wchar_t >* )( params + 24 ) = OutError;
				*( bool* )( params + 36 ) = bSpectator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutError = *( ScriptArray< wchar_t >* )( params + 24 );
			}

			bool CheckIPPolicy( ScriptArray< wchar_t > Address )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.CheckIPPolicy" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Address;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsIDBanned( void* &NetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AccessControl.IsIDBanned" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = NetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NetId = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
