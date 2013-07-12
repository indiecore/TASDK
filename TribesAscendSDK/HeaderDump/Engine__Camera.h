#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.Camera." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.Camera." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.Camera." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Camera : public Actor
	{
	public:
			ADD_OBJECT( CameraModifier_CameraShake, CameraShakeCamMod )
			ADD_OBJECT( CameraAnimInst, AnimInstPool )
			ADD_OBJECT( DynamicCameraActor, AnimCameraActor )
			ADD_VAR( ::FloatProperty, DefaultFOV, 0xFFFFFFFF )
			ADD_OBJECT( PlayerController, PCOwner )
			ADD_VAR( ::BoolProperty, bLockedFOV, 0x1 )
			ADD_VAR( ::FloatProperty, LockedFOV, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableColorScaling, 0x8 )
			ADD_STRUCT( ::VectorProperty, ColorScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OriginalColorScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DesiredColorScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ColorScaleInterpStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ColorScaleInterpDuration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableColorScaleInterp, 0x10 )
			ADD_VAR( ::BoolProperty, bConstrainAspectRatio, 0x2 )
			ADD_VAR( ::FloatProperty, CamOverridePostProcessAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConstrainedAspectRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendTimeToGo, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableFading, 0x4 )
			ADD_VAR( ::FloatProperty, FadeTimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeAmount, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FreeCamOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FreeCamDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OffAxisPitchAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OffAxisYawAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultAspectRatio, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, CameraStyle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
