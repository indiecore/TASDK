#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDroppedPickup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDroppedPickup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDroppedPickup." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDroppedPickup : public UTDroppedPickup
	{
	public:
			ADD_VAR( ::BoolProperty, m_bHasHitObjective, 0x1 )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxy )
			ADD_VAR( ::FloatProperty, m_fMarkerOpacity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentMarkerTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rMarkerRot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMarkerBlinkSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMarkerScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMarkerZOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_PctAmmoToRefill, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_AmmoPickupSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
