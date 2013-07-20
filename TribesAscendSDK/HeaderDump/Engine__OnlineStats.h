#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineStats." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineStats." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineStats." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineStats : public Object
	{
	public:
			bool GetViewId( ScriptName ViewName, int &ViewId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStats.GetViewId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ViewName;
				*( int* )( params + 8 ) = ViewId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ViewId = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetViewName( int ViewId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStats.GetViewName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ViewId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
