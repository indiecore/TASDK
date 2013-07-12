#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.RB_Spring." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.RB_Spring." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.RB_Spring." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_Spring : public ActorComponent
	{
	public:
			ADD_VAR( ::FloatProperty, DampMaxForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DampSaturateVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxForceMassRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpringMaxForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpringSaturateDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinBodyMass, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeSinceActivation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableForceMassRatio, 0x2 )
			ADD_VAR( ::BoolProperty, bInHardware, 0x1 )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName2, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName1, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
