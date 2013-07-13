#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice_Deployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice_Deployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice_Deployable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_Deployable : public TrDevice
	{
	public:
			ADD_STRUCT( ::RotatorProperty, m_rDesiredPlacementRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vDesiredPlacementLocation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bIgnoreCollisionForPlacement, 0x1 )
			ADD_VAR( ::FloatProperty, m_fOutsideCheckDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOtherDeployableProximityCheck, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vDeployVolumePlacementExtent, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vPlacementExtent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPlacementScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPerPlayerMaxDeployed, 0xFFFFFFFF )
			ADD_OBJECT( TrDeployableHologram, c_DeployableHologram )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
