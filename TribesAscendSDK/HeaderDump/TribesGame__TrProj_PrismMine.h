#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_PrismMine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_PrismMine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_PrismMine." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_PrismMine : public TrProj_Mine
	{
	public:
			ADD_STRUCT( ::VectorProperty, r_vRightHit, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_vLeftHit, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_nSocketTraceName, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, m_LaserTemplate )
			ADD_VAR( ::FloatProperty, m_fTripDistance, 0xFFFFFFFF )
			ADD_OBJECT( TrTripActor, m_TripActor )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
