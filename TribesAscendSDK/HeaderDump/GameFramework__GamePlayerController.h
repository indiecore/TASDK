#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GamePlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GamePlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GamePlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GamePlayerController : public PlayerController
	{
	public:
			ADD_VAR( ::NameProperty, CurrentSoundMode, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AgentAwareRadius, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsWarmupPaused, 0x4 )
			ADD_VAR( ::BoolProperty, bDebugCrowdAwareness, 0x2 )
			ADD_VAR( ::BoolProperty, bWarnCrowdMembers, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
