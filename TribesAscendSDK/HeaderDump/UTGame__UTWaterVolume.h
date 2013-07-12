#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTWaterVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTWaterVolume." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTWaterVolume." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTWaterVolume : public WaterVolume
	{
	public:
			ADD_OBJECT( ParticleSystem, ProjectileEntryEffect )
			ADD_OBJECT( ParticleSystem, PS_EnterWaterEffect_Vehicle )
			ADD_OBJECT( ParticleSystem, PS_EnterWaterEffect_Pawn )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
