#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SceneCaptureCubeMapComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SceneCaptureCubeMapComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SceneCaptureCubeMapComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SceneCaptureCubeMapComponent : public SceneCaptureComponent
	{
	public:
			ADD_STRUCT( ::VectorProperty, WorldLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FarPlane, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NearPlane, 0xFFFFFFFF )
			ADD_OBJECT( TextureRenderTargetCube, TextureTarget )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
