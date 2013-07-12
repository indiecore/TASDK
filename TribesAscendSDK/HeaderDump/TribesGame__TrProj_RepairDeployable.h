#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrProj_RepairDeployable." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrProj_RepairDeployable." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrProj_RepairDeployable." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_RepairDeployable : public TrProj_Mine
	{
	public:
			ADD_VAR( ::FloatProperty, m_fTickFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeSinceLastTick, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, RepairBeamSound )
			ADD_VAR( ::FloatProperty, m_fVehicleRepairPercentage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRepairPercentage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRepairBuff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRepairRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCheckNearbyActorsFrequency, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
