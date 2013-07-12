#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ActorFactoryRigidBody." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ActorFactoryRigidBody." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ActorFactoryRigidBody." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactoryRigidBody : public ActorFactoryDynamicSM
	{
	public:
			ADD_VAR( ::FloatProperty, StayUprightMaxTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StayUprightTorqueFactor, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RBChannel, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitialVelocity, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableStayUprightSpring, 0x8 )
			ADD_VAR( ::BoolProperty, bLocalSpaceInitialVelocity, 0x4 )
			ADD_VAR( ::BoolProperty, bDamageAppliesImpulse, 0x2 )
			ADD_VAR( ::BoolProperty, bStartAwake, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
