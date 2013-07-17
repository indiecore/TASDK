#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Input." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Input." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Input." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Input : public Interaction
	{
	public:
			ADD_VAR( ::FloatProperty, CurrentDeltaTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentDelta, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentEvent, 0xFFFFFFFF )
			void ResetInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Input.ResetInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetBind( ScriptName &Key )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Input.GetBind" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = Key;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Key = *( ScriptName* )( params + 0 );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetBindNameFromCommandScript( ScriptArray< wchar_t > &KeyCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Input.GetBindNameFromCommandScript" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = KeyCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				KeyCommand = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetBind( ScriptName &BindName, ScriptArray< wchar_t > Command )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Input.SetBind" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = BindName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Command;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BindName = *( ScriptName* )( params + 0 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
