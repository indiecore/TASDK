#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.EmitterCameraLensEffectBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.EmitterCameraLensEffectBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.EmitterCameraLensEffectBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class EmitterCameraLensEffectBase : public Emitter
	{
	public:
			ADD_VAR( ::BoolProperty, bAllowMultipleInstances, 0x1 )
			ADD_OBJECT( Camera, BaseCamera )
			ADD_VAR( ::FloatProperty, DistFromCamera, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseFOV, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, PS_CameraEffectNonExtremeContent )
			ADD_OBJECT( ParticleSystem, PS_CameraEffect )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
