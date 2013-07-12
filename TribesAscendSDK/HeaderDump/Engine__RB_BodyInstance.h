#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.RB_BodyInstance." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.RB_BodyInstance." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.RB_BodyInstance." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_BodyInstance : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, InstanceDampingScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InstanceMassScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ContactReportForceThreshold, 0xFFFFFFFF )
			ADD_OBJECT( PhysicalMaterial, PhysMaterialOverride )
			ADD_VAR( ::FloatProperty, LastEffectPlayedTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CustomGravityFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OverextensionThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneAngularDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneAngularSpring, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneLinearDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneLinearSpring, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInstanceAlwaysFullAnimWeight, 0x800 )
			ADD_VAR( ::BoolProperty, bForceUnfixed, 0x400 )
			ADD_VAR( ::BoolProperty, bPushBody, 0x200 )
			ADD_VAR( ::BoolProperty, bEnableCollisionResponse, 0x100 )
			ADD_VAR( ::BoolProperty, bOnlyCollideWithPawns, 0x80 )
			ADD_VAR( ::BoolProperty, bMakeSpringToBaseCollisionComponent, 0x40 )
			ADD_VAR( ::BoolProperty, bUseKinActorForBoneSpring, 0x20 )
			ADD_VAR( ::BoolProperty, bTeleportOnOverextension, 0x10 )
			ADD_VAR( ::BoolProperty, bNotifyOwnerOnOverextension, 0x8 )
			ADD_VAR( ::BoolProperty, bDisableOnOverextension, 0x4 )
			ADD_VAR( ::BoolProperty, bEnableBoneSpringAngular, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableBoneSpringLinear, 0x1 )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreviousVelocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Velocity, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BodyIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
