#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTPawnSoundGroup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTPawnSoundGroup." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTPawnSoundGroup." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTPawnSoundGroup : public Object
	{
	public:
			ADD_OBJECT( SoundCue, InstagibSound )
			ADD_OBJECT( SoundCue, BodyExplosionSound )
			ADD_OBJECT( SoundCue, CrushedSound )
			ADD_OBJECT( SoundCue, BulletImpactSound )
			ADD_OBJECT( SoundCue, DefaultLandingSound )
			ADD_OBJECT( SoundCue, DefaultFootstepSound )
			ADD_OBJECT( SoundCue, GaspSound )
			ADD_OBJECT( SoundCue, DrownSound )
			ADD_OBJECT( SoundCue, GibSound )
			ADD_OBJECT( SoundCue, HitSounds )
			ADD_OBJECT( SoundCue, DyingSound )
			ADD_OBJECT( SoundCue, FallingDamageLandSound )
			ADD_OBJECT( SoundCue, LandSound )
			ADD_OBJECT( SoundCue, DefaultJumpingSound )
			ADD_OBJECT( SoundCue, DoubleJumpSound )
			ADD_OBJECT( SoundCue, DodgeSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
