#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrStormControlPoint." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrStormControlPoint." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrStormControlPoint." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrStormControlPoint : public TrGameObjective
	{
	public:
			ADD_VAR( ::StrProperty, m_sControlPointName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLaunchTimeDescriptionPlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fControlDescriptionPlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMissileFlightTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMissileLaunchTrackerSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMissileLaunchTracker, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentTransitionAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTransitionSpeed, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_CurrentControlPointState, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
