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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
