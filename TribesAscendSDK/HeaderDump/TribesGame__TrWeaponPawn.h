#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrWeaponPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrWeaponPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrWeaponPawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrWeaponPawn : public UTWeaponPawn
	{
	public:
			ADD_VAR( ::FloatProperty, m_fCurrentAccuracy, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nFlashReload, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, r_scFiringLoop )
			ADD_VAR( ::BoolProperty, r_bFiringLoopSound, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
