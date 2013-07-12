#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.TextureRenderTarget2D." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.TextureRenderTarget2D." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.TextureRenderTarget2D." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TextureRenderTarget2D : public TextureRenderTarget
	{
	public:
			ADD_VAR( ::BoolProperty, bForceLinearGamma, 0x1 )
			ADD_VAR( ::ByteProperty, AddressY, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AddressX, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Format, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
