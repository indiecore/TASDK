#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDeployable_PrismMine." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDeployable_PrismMine." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDeployable_PrismMine." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_PrismMine : public TrDeployable
	{
	public:
			ADD_OBJECT( SoundCue, m_HitSound )
			ADD_OBJECT( SoundCue, m_DeactivateSound )
			ADD_OBJECT( SoundCue, m_ActivateSound )
			ADD_OBJECT( ParticleSystem, m_LaserTemplate )
			ADD_VAR( ::IntProperty, m_DamageAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSleepTimeAfterHit, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_nSocketTraceName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPrismRadius, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
