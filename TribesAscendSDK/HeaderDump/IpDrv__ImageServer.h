#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.ImageServer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.ImageServer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.ImageServer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ImageServer : public WebApplication
	{
	public:
			void Query( class WebRequest* Request, class WebResponse* Response )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.ImageServer.Query" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class WebRequest** )params = Request;
				*( class WebResponse** )( params + 4 ) = Response;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
