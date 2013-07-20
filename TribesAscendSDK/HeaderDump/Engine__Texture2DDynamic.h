#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Texture2DDynamic." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Texture2DDynamic." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Texture2DDynamic." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Texture2DDynamic : public Texture
	{
	public:
			ADD_VAR( ::BoolProperty, bIsResolveTarget, 0x1 )
			ADD_VAR( ::IntProperty, NumMips, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Format, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
			void Init( int InSizeX, int InSizeY, byte InFormat, bool InIsResolveTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Texture2DDynamic.Init" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( int* )params = InSizeX;
				*( int* )( params + 4 ) = InSizeY;
				*( byte* )( params + 8 ) = InFormat;
				*( bool* )( params + 12 ) = InIsResolveTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Texture2DDynamic* Create( int InSizeX, int InSizeY, byte InFormat, bool InIsResolveTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Texture2DDynamic.Create" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( int* )params = InSizeX;
				*( int* )( params + 4 ) = InSizeY;
				*( byte* )( params + 8 ) = InFormat;
				*( bool* )( params + 12 ) = InIsResolveTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture2DDynamic** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
