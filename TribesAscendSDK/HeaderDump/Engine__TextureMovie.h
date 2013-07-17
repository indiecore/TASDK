#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TextureMovie." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TextureMovie." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TextureMovie." #y ); \
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
			ADD_OBJECT( ScriptClass, DecoderClass )
			ADD_VAR( ::ByteProperty, MovieStreamSource, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AddressY, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AddressX, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Format, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			void Play(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TextureMovie.Play" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Pause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TextureMovie.Pause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Stop(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TextureMovie.Stop" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
