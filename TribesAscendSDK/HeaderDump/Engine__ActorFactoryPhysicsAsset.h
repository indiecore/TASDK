#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ActorFactoryPhysicsAsset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ActorFactoryPhysicsAsset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ActorFactoryPhysicsAsset." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactoryPhysicsAsset : public ActorFactory
	{
	public:
			ADD_STRUCT( ::VectorProperty, DrawScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitialVelocity, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCastDynamicShadow, 0x10 )
			ADD_VAR( ::BoolProperty, bUseCompartment, 0x8 )
			ADD_VAR( ::BoolProperty, bNotifyRigidBodyCollision, 0x4 )
			ADD_VAR( ::BoolProperty, bDamageAppliesImpulse, 0x2 )
			ADD_VAR( ::BoolProperty, bStartAwake, 0x1 )
			ADD_OBJECT( SkeletalMesh, SkeletalMesh )
			ADD_OBJECT( PhysicsAsset, PhysicsAsset )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
