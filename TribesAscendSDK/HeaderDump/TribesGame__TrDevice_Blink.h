#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDevice_Blink." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDevice_Blink." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDevice_Blink." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_Blink : public TrDevice_Pack
	{
	public:
			ADD_VAR( ::FloatProperty, m_fMinZImpulse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPowerPoolCost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCapThresholdStart, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCapPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCapThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastActivationTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCooldownTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vBlinkImpulse, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
