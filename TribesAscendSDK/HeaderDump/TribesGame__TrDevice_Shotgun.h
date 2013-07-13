#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice_Shotgun." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice_Shotgun." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice_Shotgun." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_Shotgun : public TrDevice
	{
	public:
			ADD_OBJECT( AnimNodePlayCustomAnim, ReloadCustomAnimNode )
			ADD_VAR( ::IntProperty, m_nConsumeShotsFired, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nShotsFired, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInnerDefaultAccuracy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fConsumeAmmoTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nImpactCounter, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMinShotCount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
