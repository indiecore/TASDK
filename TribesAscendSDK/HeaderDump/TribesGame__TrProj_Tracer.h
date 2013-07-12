#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrProj_Tracer." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrProj_Tracer." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrProj_Tracer." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_Tracer : public TrProjectile
	{
	public:
			ADD_STRUCT( ::VectorProperty, m_vTracerDrawScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vInitialFrameOfRefVelocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vDestinationLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMeshScaleDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bScalingDown, 0x2 )
			ADD_VAR( ::BoolProperty, m_bScaledUp, 0x1 )
			ADD_VAR( ::FloatProperty, m_fMeshScaleUpTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccelRate, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
