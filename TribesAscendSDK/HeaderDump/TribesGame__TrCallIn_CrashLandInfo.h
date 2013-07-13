#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn_CrashLandInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn_CrashLandInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn_CrashLandInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn_CrashLandInfo : public Info
	{
	public:
			ADD_VAR( ::FloatProperty, MomentumTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Damage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageRadius, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_CrashLandNormal, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_CrashLandPoint, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fCrashLandTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bPodLanded, 0x1 )
			ADD_OBJECT( Controller, m_Owner )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
