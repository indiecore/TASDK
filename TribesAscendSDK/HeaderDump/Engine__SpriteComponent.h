#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SpriteComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SpriteComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SpriteComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SpriteComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::FloatProperty, VL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, V, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, U, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ScreenSize, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsScreenSizeScaled, 0x1 )
			ADD_OBJECT( Texture2D, Sprite )
			void SetSprite( class Texture2D* NewSprite )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpriteComponent.SetSprite" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Texture2D** )( params + 0 ) = NewSprite;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetUV( int NewU, int NewUL, int NewV, int NewVL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpriteComponent.SetUV" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = NewU;
				*( int* )( params + 4 ) = NewUL;
				*( int* )( params + 8 ) = NewV;
				*( int* )( params + 12 ) = NewVL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSpriteAndUV( class Texture2D* NewSprite, int NewU, int NewUL, int NewV, int NewVL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpriteComponent.SetSpriteAndUV" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Texture2D** )( params + 0 ) = NewSprite;
				*( int* )( params + 4 ) = NewU;
				*( int* )( params + 8 ) = NewUL;
				*( int* )( params + 12 ) = NewV;
				*( int* )( params + 16 ) = NewVL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
