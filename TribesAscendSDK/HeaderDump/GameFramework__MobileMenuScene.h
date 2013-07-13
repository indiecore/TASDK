#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.MobileMenuScene." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.MobileMenuScene." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.MobileMenuScene." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MobileMenuScene : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, Width, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Height, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Left, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Top, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Opacity, 0xFFFFFFFF )
			ADD_OBJECT( Font, SceneCaptionFont )
			ADD_OBJECT( SoundCue, UIUnTouchSound )
			ADD_OBJECT( SoundCue, UITouchSound )
			ADD_VAR( ::FloatProperty, AuthoredGlobalScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bApplyGlobalScaleHeight, 0x100 )
			ADD_VAR( ::BoolProperty, bApplyGlobalScaleWidth, 0x80 )
			ADD_VAR( ::BoolProperty, bApplyGlobalScaleTop, 0x40 )
			ADD_VAR( ::BoolProperty, bApplyGlobalScaleLeft, 0x20 )
			ADD_VAR( ::BoolProperty, bRelativeHeight, 0x10 )
			ADD_VAR( ::BoolProperty, bRelativeWidth, 0x8 )
			ADD_VAR( ::BoolProperty, bRelativeTop, 0x4 )
			ADD_VAR( ::BoolProperty, bRelativeLeft, 0x2 )
			ADD_VAR( ::BoolProperty, bSceneDoesNotRequireInput, 0x1 )
			ADD_OBJECT( MobilePlayerInput, InputOwner )
			ADD_VAR( ::StrProperty, MenuName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
