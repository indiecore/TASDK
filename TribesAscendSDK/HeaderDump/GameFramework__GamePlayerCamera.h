#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GamePlayerCamera." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GamePlayerCamera." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GamePlayerCamera." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GamePlayerCamera : public Camera
	{
	public:
			ADD_OBJECT( Actor, LastTargetBase )
			ADD_VAR( ::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF )
			ADD_OBJECT( Actor, LastViewTarget )
			ADD_VAR( ::FloatProperty, ForcedCamFOV, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bResetInterp, 0x4 )
			ADD_VAR( ::BoolProperty, bInterpolateCamChanges, 0x2 )
			ADD_VAR( ::BoolProperty, bUseForcedCamFOV, 0x1 )
			ADD_OBJECT( GameCameraBase, CurrentCamera )
			ADD_OBJECT( GameCameraBase, FixedCam )
			ADD_OBJECT( GameCameraBase, ThirdPersonCam )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
