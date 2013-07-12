#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrProj_Mine." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrProj_Mine." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrProj_Mine." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_Mine : public TrProjectile
	{
	public:
			ADD_OBJECT( PlayerReplicationInfo, r_OwnerPRI )
			ADD_VAR( ::IntProperty, m_nIconStackId, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_VAR( ::IntProperty, m_nMarkerOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShowHeaderUntil, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_sScreenName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNumBouncesBeforeDetonateObsolete, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNumBounces, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxFloorZ, 0xFFFFFFFF )
			ADD_OBJECT( TrMineCollisionProxy, m_CollisionProxy )
			ADD_VAR( ::FloatProperty, m_fDetonationHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDetonationRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDeploySeconds, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bIsPostRendered, 0x10 )
			ADD_VAR( ::BoolProperty, bPostRenderTraceSucceeded, 0x8 )
			ADD_VAR( ::BoolProperty, m_bDrawOwnerName, 0x4 )
			ADD_VAR( ::BoolProperty, m_bUsesDetonationProxy, 0x2 )
			ADD_VAR( ::BoolProperty, m_bArmed, 0x1 )
			ADD_OBJECT( SoundCue, WallImpactSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
