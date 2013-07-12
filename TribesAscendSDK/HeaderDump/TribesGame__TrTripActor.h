#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrTripActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrTripActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrTripActor." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrTripActor : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, m_fSleepTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, r_Left )
			ADD_OBJECT( Actor, r_Right )
			ADD_VAR( ::BoolProperty, m_bRequiresTwoNotifiers, 0x4 )
			ADD_OBJECT( ParticleSystem, m_LaserTemplate )
			ADD_VAR( ::FloatProperty, r_fSleepEndTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bIsInitialized, 0x2 )
			ADD_VAR( ::BoolProperty, r_bIsPowered, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
