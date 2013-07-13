#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleSpawnPerUnit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleSpawnPerUnit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleSpawnPerUnit." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleSpawnPerUnit : public ParticleModuleSpawnBase
	{
	public:
			ADD_VAR( ::FloatProperty, MovementTolerance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIgnoreMovementAlongZ, 0x8 )
			ADD_VAR( ::BoolProperty, bIgnoreMovementAlongY, 0x4 )
			ADD_VAR( ::BoolProperty, bIgnoreMovementAlongX, 0x2 )
			ADD_VAR( ::BoolProperty, bIgnoreSpawnRateWhenMoving, 0x1 )
			ADD_VAR( ::FloatProperty, UnitScalar, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
