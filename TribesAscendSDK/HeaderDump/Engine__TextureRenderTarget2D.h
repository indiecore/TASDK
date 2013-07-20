#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TextureRenderTarget2D." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TextureRenderTarget2D." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TextureRenderTarget2D." #y ); \
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
			class TextureRenderTarget2D* Create( int InSizeX, int InSizeY, byte InFormat, void* InClearColor, bool bOnlyRenderOnce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TextureRenderTarget2D.Create" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( int* )params = InSizeX;
				*( int* )( params + 4 ) = InSizeY;
				*( byte* )( params + 8 ) = InFormat;
				*( void** )( params + 12 ) = InClearColor;
				*( bool* )( params + 28 ) = bOnlyRenderOnce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TextureRenderTarget2D** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
