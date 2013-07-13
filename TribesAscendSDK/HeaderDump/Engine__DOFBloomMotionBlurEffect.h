#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DOFBloomMotionBlurEffect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DOFBloomMotionBlurEffect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DOFBloomMotionBlurEffect." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DOFBloomMotionBlurEffect : public DOFAndBloomEffect
	{
	public:
			ADD_VAR( ::FloatProperty, CameraTranslationThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraRotationThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, FullMotionBlur, 0x1 )
			ADD_VAR( ::FloatProperty, MotionBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxVelocity, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
