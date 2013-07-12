#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameThirdPersonCameraMode_Default." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameThirdPersonCameraMode_Default." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameThirdPersonCameraMode_Default." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameThirdPersonCameraMode_Default : public GameThirdPersonCameraMode
	{
	public:
			ADD_VAR( ::FloatProperty, TemporaryOriginRotInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTemporaryOriginRotInterp, 0x1 )
			ADD_VAR( ::FloatProperty, WorstLocAimingZOffset, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
