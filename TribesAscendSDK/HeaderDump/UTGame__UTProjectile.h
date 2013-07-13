#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTProjectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTProjectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTProjectile." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTProjectile : public UDKProjectile
	{
	public:
			ADD_VAR( ::FloatProperty, GlobalCheckRadiusTweak, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TossZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxEffectDistance, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DecalDissolveParamName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DurationOfDecal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DecalHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DecalWidth, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, ExplosionDecal )
			ADD_OBJECT( ParticleSystem, ProjExplosionTemplate )
			ADD_OBJECT( ParticleSystem, ProjFlightTemplate )
			ADD_OBJECT( SoundCue, ExplosionSound )
			ADD_OBJECT( SoundCue, AmbientSound )
			ADD_VAR( ::BoolProperty, bAttachExplosionToVehicles, 0x40 )
			ADD_VAR( ::BoolProperty, bWaitForEffects, 0x20 )
			ADD_VAR( ::BoolProperty, bSuppressExplosionFX, 0x10 )
			ADD_VAR( ::BoolProperty, bAdvanceExplosionEffect, 0x8 )
			ADD_VAR( ::BoolProperty, m_bDestroyProjEffects, 0x4 )
			ADD_VAR( ::BoolProperty, bImportantAmbientSound, 0x2 )
			ADD_VAR( ::BoolProperty, bSuppressSounds, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
