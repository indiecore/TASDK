#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable_ForceField." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_ForceField : public TrDeployable
	{
	public:
			ADD_VAR( ::FloatProperty, m_LightFlashBrightness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutHitOtherFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInHitOtherFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutHitOtherFlashTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInHitOtherFlashTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutTakeHitFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInTakeHitFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutTakeHitFlashTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInTakeHitFlashTimeLength, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
