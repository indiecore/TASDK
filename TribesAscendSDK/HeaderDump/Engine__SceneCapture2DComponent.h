#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SceneCapture2DComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SceneCapture2DComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SceneCapture2DComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SceneCapture2DComponent : public SceneCaptureComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bUpdateMatrices, 0x1 )
			ADD_VAR( ::FloatProperty, FarPlane, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NearPlane, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FieldOfView, 0xFFFFFFFF )
			ADD_OBJECT( TextureRenderTarget2D, TextureTarget )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
