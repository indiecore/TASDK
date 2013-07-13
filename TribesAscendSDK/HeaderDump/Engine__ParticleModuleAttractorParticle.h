#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleAttractorParticle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleAttractorParticle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleAttractorParticle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleAttractorParticle : public ParticleModuleAttractorBase
	{
	public:
			ADD_VAR( ::IntProperty, LastSelIndex, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SelectionMethod, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, EmitterName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInheritSourceVel, 0x8 )
			ADD_VAR( ::BoolProperty, bRenewSource, 0x4 )
			ADD_VAR( ::BoolProperty, bAffectBaseVelocity, 0x2 )
			ADD_VAR( ::BoolProperty, bStrengthByDistance, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
