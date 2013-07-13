#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PhysicsVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PhysicsVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PhysicsVolume." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PhysicsVolume : public Volume
	{
	public:
			ADD_VAR( ::BoolProperty, bPainCausing, 0x2 )
			ADD_VAR( ::FloatProperty, DamagePerSec, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWaterVolume, 0x1000 )
			ADD_OBJECT( PhysicsVolume, NextPhysicsVolume )
			ADD_OBJECT( Controller, DamageInstigator )
			ADD_OBJECT( Info, PainTimer )
			ADD_VAR( ::FloatProperty, MaxDampingForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RigidBodyDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PainInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidFriction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Priority, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TerminalVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroundFriction, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPhysicsOnContact, 0x800 )
			ADD_VAR( ::BoolProperty, bCrowdAgentsPlayDeathAnim, 0x400 )
			ADD_VAR( ::BoolProperty, bNeutralZone, 0x200 )
			ADD_VAR( ::BoolProperty, bBounceVelocity, 0x100 )
			ADD_VAR( ::BoolProperty, bMoveProjectiles, 0x80 )
			ADD_VAR( ::BoolProperty, bNoInventory, 0x40 )
			ADD_VAR( ::BoolProperty, bDestructive, 0x20 )
			ADD_VAR( ::BoolProperty, BACKUP_bPainCausing, 0x10 )
			ADD_VAR( ::BoolProperty, bEntryPain, 0x8 )
			ADD_VAR( ::BoolProperty, bAIShouldIgnorePain, 0x4 )
			ADD_VAR( ::BoolProperty, bVelocityAffectsWalking, 0x1 )
			ADD_STRUCT( ::VectorProperty, ZoneVelocity, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
