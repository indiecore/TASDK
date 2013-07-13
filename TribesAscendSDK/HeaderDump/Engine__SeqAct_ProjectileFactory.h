#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_ProjectileFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_ProjectileFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_ProjectileFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ProjectileFactory : public SeqAct_ActorFactory
	{
	public:
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SocketName, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, PSTemplate )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
