#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrVehicle_BaseFlying." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrVehicle_BaseFlying." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrVehicle_BaseFlying." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicle_BaseFlying : public TrVehicle
	{
	public:
			ADD_VAR( ::BoolProperty, m_bCanAutoLevelVehicle, 0x2 )
			ADD_VAR( ::BoolProperty, m_bFreeLook, 0x1 )
			ADD_VAR( ::FloatProperty, m_fBoostThrustInvDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostThrustBuildUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fThrustInvDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fThrustBuildUp, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
