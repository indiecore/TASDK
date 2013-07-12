#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SceneCapture2DHitMaskComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SceneCapture2DHitMaskComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SceneCapture2DHitMaskComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SceneCapture2DHitMaskComponent : public SceneCaptureComponent
	{
	public:
			ADD_VAR( ::FloatProperty, FadingIntervalTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadingDurationTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadingPercentage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadingStartTimeSinceHit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HitMaskCullDistance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ForceLOD, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaterialIndex, 0xFFFFFFFF )
			ADD_OBJECT( TextureRenderTarget2D, TextureTarget )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
