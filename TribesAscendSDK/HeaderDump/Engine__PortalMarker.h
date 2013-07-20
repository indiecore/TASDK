#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PortalMarker." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PortalMarker." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PortalMarker." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PortalMarker : public NavigationPoint
	{
	public:
			ADD_OBJECT( PortalTeleporter, MyPortal )
			bool CanTeleport( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PortalMarker.CanTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
