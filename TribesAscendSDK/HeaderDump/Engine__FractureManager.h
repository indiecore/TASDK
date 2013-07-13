#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.FractureManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.FractureManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.FractureManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FractureManager : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, ExplosionVelScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DestroyMinAngVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DestroyVibrationLevel, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableSpawnChunkEffectForRadialDamage, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableAntiVibration, 0x1 )
			ADD_VAR( ::IntProperty, FSMPartPoolSize, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
