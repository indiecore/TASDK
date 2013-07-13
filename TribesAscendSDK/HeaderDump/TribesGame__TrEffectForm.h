#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrEffectForm." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrEffectForm." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrEffectForm." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrEffectForm : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, m_bIsManaged, 0x2 )
			ADD_OBJECT( Material, m_BodyMat )
			ADD_VAR( ::ByteProperty, m_ePriority, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bApplied, 0x1 )
			ADD_OBJECT( SoundCue, m_SoundCue )
			ADD_OBJECT( ParticleSystem, m_PSC )
			ADD_VAR( ::ByteProperty, m_eMatType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBodyMatFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBodyMatFadeInTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
