#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MultiFont." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MultiFont." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MultiFont." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MultiFont : public Font
	{
	public:
			int GetResolutionTestTableIndex( float HeightTest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MultiFont.GetResolutionTestTableIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = HeightTest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
