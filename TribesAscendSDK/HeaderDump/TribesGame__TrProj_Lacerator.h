#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_Lacerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_Lacerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_Lacerator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_Lacerator : public TrProjectile
	{
	public:
			ADD_OBJECT( CameraAnim, ShortRangeKillAnim )
			ADD_VAR( ::BoolProperty, bShrinking, 0x2 )
			ADD_VAR( ::BoolProperty, bCheckShortRangeKill, 0x1 )
			ADD_OBJECT( SoundCue, HitPawnSound )
			ADD_OBJECT( ParticleSystem, RockSmokeTemplate )
			ADD_OBJECT( ParticleSystem, BounceTemplate )
			ADD_VAR( ::FloatProperty, ShrinkTimer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageAttenuation, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Bounces, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
