#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleLODLevel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleLODLevel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleLODLevel." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleLODLevel : public Object
	{
	public:
			ADD_VAR( ::IntProperty, PeakActiveParticles, 0xFFFFFFFF )
			ADD_OBJECT( ParticleModuleEventGenerator, EventGenerator )
			ADD_OBJECT( ParticleModuleSpawn, SpawnModule )
			ADD_OBJECT( ParticleModule, TypeDataModule )
			ADD_OBJECT( ParticleModuleRequired, RequiredModule )
			ADD_VAR( ::BoolProperty, ConvertedModules, 0x2 )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			ADD_VAR( ::IntProperty, Level, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
