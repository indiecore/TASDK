#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDevice_ConstantFire." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDevice_ConstantFire." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDevice_ConstantFire." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_ConstantFire : public TrDevice
	{
	public:
			ADD_VAR( ::NameProperty, m_PostFireState, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_FireTail )
			ADD_VAR( ::FloatProperty, WeaponFireFadeTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bIsCurrentlyFiring, 0x4 )
			ADD_VAR( ::BoolProperty, m_bHasLoopingFireAnim, 0x2 )
			ADD_VAR( ::BoolProperty, m_bSoundLinkedWithState, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
