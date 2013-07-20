#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxFSCmdHandler_Kismet." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxFSCmdHandler_Kismet." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxFSCmdHandler_Kismet." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxFSCmdHandler_Kismet : public GFxFSCmdHandler
	{
	public:
			bool FSCommand( class GFxMoviePlayer* Movie, class GFxEvent_FSCommand* Event, ScriptArray< wchar_t > Cmd, ScriptArray< wchar_t > Arg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxFSCmdHandler_Kismet.FSCommand" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class GFxMoviePlayer** )params = Movie;
				*( class GFxEvent_FSCommand** )( params + 4 ) = Event;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Cmd;
				*( ScriptArray< wchar_t >* )( params + 20 ) = Arg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
