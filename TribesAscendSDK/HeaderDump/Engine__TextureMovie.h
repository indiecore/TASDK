#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.TextureMovie." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.TextureMovie." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.TextureMovie." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TextureMovie : public Texture
	{
	public:
			ADD_VAR( ::BoolProperty, AutoPlay, 0x8 )
			ADD_VAR( ::BoolProperty, Looping, 0x4 )
			ADD_VAR( ::BoolProperty, Stopped, 0x2 )
			ADD_VAR( ::BoolProperty, Paused, 0x1 )
			ADD_OBJECT( CodecMovie, Decoder )
			ADD_VAR( ::ByteProperty, MovieStreamSource, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AddressY, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AddressX, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Format, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
