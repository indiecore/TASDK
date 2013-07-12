#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrSpottedTarget." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrSpottedTarget." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrSpottedTarget." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSpottedTarget : public Actor
	{
	public:
			ADD_OBJECT( Actor, m_SpottedActor )
			ADD_VAR( ::FloatProperty, m_fLastSpottedTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpottedActorDuration, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_VAR( ::FloatProperty, m_fMarkerOpacity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMarkerZOffset, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_CachedTeamIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
