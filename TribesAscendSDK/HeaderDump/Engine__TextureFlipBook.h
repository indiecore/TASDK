#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TextureFlipBook." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TextureFlipBook." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TextureFlipBook." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TextureFlipBook : public Texture2D
	{
	public:
			ADD_VAR( ::FloatProperty, RenderOffsetV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RenderOffsetU, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentColumn, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentRow, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FrameTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FrameRate, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FBMethod, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VerticalImages, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HorizontalImages, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoPlay, 0x8 )
			ADD_VAR( ::BoolProperty, bLooping, 0x4 )
			ADD_VAR( ::BoolProperty, bStopped, 0x2 )
			ADD_VAR( ::BoolProperty, bPaused, 0x1 )
			ADD_VAR( ::FloatProperty, VerticalScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HorizontalScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeSinceLastFrame, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeIntoMovie, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
